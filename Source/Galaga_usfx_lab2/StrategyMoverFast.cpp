// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyMoverFast.h"
#include "Galaga_usfx_lab2Pawn.h"

// Sets default values
AStrategyMoverFast::AStrategyMoverFast()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyMoverFast::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyMoverFast::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyMoverFast::Mover(AGalaga_usfx_lab2Pawn* Pawn, float DeltaTime)
{
	// Verificar si el Pawn es válido
	if (Pawn)
	{
		// Teletransportar el Pawn al borde izquierdo
		Pawn->SetActorLocation(FVector(-1500.0f, Pawn->GetActorLocation().Y, Pawn->GetActorLocation().Z));

		// Llamar a la función para restablecer el movimiento después del teletransporte
		Pawn->ResetMovementAfterTeleport();
	}
}