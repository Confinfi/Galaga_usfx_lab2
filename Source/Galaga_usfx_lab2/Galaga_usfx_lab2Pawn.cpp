// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_usfx_lab2Pawn.h"
#include "Galaga_usfx_lab2Projectile.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/CollisionProfile.h"
#include "Engine/StaticMesh.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "StrategyMoverDerecha.h"
#include "StrategyMoverIzquierda.h"
#include "StrategyMoverFast.h"
#include "IStrategyPawn.h"

const FName AGalaga_usfx_lab2Pawn::MoveForwardBinding("MoveForward");
const FName AGalaga_usfx_lab2Pawn::MoveRightBinding("MoveRight");
const FName AGalaga_usfx_lab2Pawn::FireForwardBinding("FireForward");
const FName AGalaga_usfx_lab2Pawn::FireRightBinding("FireRight");

AGalaga_usfx_lab2Pawn::AGalaga_usfx_lab2Pawn()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ShipMesh(TEXT("/Game/TwinStick/Meshes/TwinStickUFO.TwinStickUFO"));
	// Create the mesh component
	ShipMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShipMesh"));
	RootComponent = ShipMeshComponent;
	ShipMeshComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	ShipMeshComponent->SetStaticMesh(ShipMesh.Object);

	// Cache our sound effect
	static ConstructorHelpers::FObjectFinder<USoundBase> FireAudio(TEXT("/Game/TwinStick/Audio/TwinStickFire.TwinStickFire"));
	FireSound = FireAudio.Object;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when ship does
	CameraBoom->TargetArmLength = 1200.f;
	CameraBoom->SetRelativeRotation(FRotator(-80.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	CameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// Camera does not rotate relative to arm

	// Movement
	MoveSpeed = 1000.0f;
	// Weapon
	GunOffset = FVector(90.f, 0.f, 0.f);
	FireRate = 0.1f;
	bCanFire = true;

	CurrentStrategy = nullptr;
}

void AGalaga_usfx_lab2Pawn::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	// Bind standard movement axes
	PlayerInputComponent->BindAxis(MoveForwardBinding);
	PlayerInputComponent->BindAxis(MoveRightBinding);
	PlayerInputComponent->BindAxis(FireForwardBinding);
	PlayerInputComponent->BindAxis(FireRightBinding);

	// Bind strategy actions
	PlayerInputComponent->BindAction("Strategia1", IE_Pressed, this, &AGalaga_usfx_lab2Pawn::SeleccionarEstrategia1);
	PlayerInputComponent->BindAction("Strategia2", IE_Pressed, this, &AGalaga_usfx_lab2Pawn::SeleccionarEstrategia2);
	PlayerInputComponent->BindAction("Strategia3", IE_Pressed, this, &AGalaga_usfx_lab2Pawn::SeleccionarEstrategia3);

	// You might also want to add bindings to release the strategies if needed:
	// PlayerInputComponent->BindAction("Strategia1", IE_Released, this, &AGalaga_usfx_lab2Pawn::DeseleccionarEstrategia1);
	// PlayerInputComponent->BindAction("Strategia2", IE_Released, this, &AGalaga_usfx_lab2Pawn::DeseleccionarEstrategia2);
	// PlayerInputComponent->BindAction("Strategia3", IE_Released, this, &AGalaga_usfx_lab2Pawn::DeseleccionarEstrategia3);
}

void AGalaga_usfx_lab2Pawn::Tick(float DeltaSeconds)
{
	if (CurrentStrategy)
	{
		CurrentStrategy->Mover(this, DeltaSeconds);

		// Si la estrategia ha sido usada, destr�yela
		if (CurrentStrategy)
		{
			CurrentStrategy = nullptr;
		}
	}
	// Find movement direction
	const float ForwardValue = GetInputAxisValue(MoveForwardBinding);
	const float RightValue = GetInputAxisValue(MoveRightBinding);

	// Clamp max size so that (X=1, Y=1) doesn't cause faster movement in diagonal directions
	const FVector MoveDirection = FVector(ForwardValue, RightValue, 0.f).GetClampedToMaxSize(1.0f);

	// Calculate  movement
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	// If non-zero size, move this actor
	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();
		FHitResult Hit(1.f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);

		if (Hit.IsValidBlockingHit())
		{
			const FVector Normal2D = Hit.Normal.GetSafeNormal2D();
			const FVector Deflection = FVector::VectorPlaneProject(Movement, Normal2D) * (1.f - Hit.Time);
			RootComponent->MoveComponent(Deflection, NewRotation, true);
		}
	}

	// Create fire direction vector
	const float FireForwardValue = GetInputAxisValue(FireForwardBinding);
	const float FireRightValue = GetInputAxisValue(FireRightBinding);
	const FVector FireDirection = FVector(FireForwardValue, FireRightValue, 0.f);

	// Try and fire a shot
	FireShot(FireDirection);
}

void AGalaga_usfx_lab2Pawn::FireShot(FVector FireDirection)
{
	// If it's ok to fire again
	if (bCanFire == true)
	{
		// If we are pressing fire stick in a direction
		if (FireDirection.SizeSquared() > 0.0f)
		{
			const FRotator FireRotation = FireDirection.Rotation();
			// Spawn projectile at an offset from this pawn
			const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

			UWorld* const World = GetWorld();
			if (World != nullptr)
			{
				// spawn the projectile
				World->SpawnActor<AGalaga_usfx_lab2Projectile>(SpawnLocation, FireRotation);
			}

			bCanFire = false;
			World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &AGalaga_usfx_lab2Pawn::ShotTimerExpired, FireRate);

			// try and play the sound if specified
			if (FireSound != nullptr)
			{
				UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
			}

			bCanFire = false;
		}
	}
}

void AGalaga_usfx_lab2Pawn::ShotTimerExpired()
{
	bCanFire = true;
}

void AGalaga_usfx_lab2Pawn::SeleccionarEstrategia1()
{
	// Liberar la estrategia actual
	CurrentStrategy = nullptr;

	// Crear y asignar una nueva estrategia
	AStrategyMoverDerecha* EstrategiaDerecha = GetWorld()->SpawnActor<AStrategyMoverDerecha>();
	CurrentStrategy = EstrategiaDerecha;
}

void AGalaga_usfx_lab2Pawn::SeleccionarEstrategia2()
{
	CurrentStrategy = nullptr;

	AStrategyMoverIzquierda* EstrategiaIzquierda = GetWorld()->SpawnActor<AStrategyMoverIzquierda>();
	CurrentStrategy = EstrategiaIzquierda;
}

void AGalaga_usfx_lab2Pawn::SeleccionarEstrategia3()
{
	CurrentStrategy = nullptr;

	AStrategyMoverFast* EstrategiaFast = GetWorld()->SpawnActor<AStrategyMoverFast>();
	CurrentStrategy = EstrategiaFast;
}
void AGalaga_usfx_lab2Pawn::ResetMovementAfterTeleport()
{
	// Reiniciar el movimiento del pawn
	bCanMove = true;
}