// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyMoverIzquierda.h"
#include "Galaga_usfx_lab2Pawn.h"

// Sets default values
AStrategyMoverIzquierda::AStrategyMoverIzquierda()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStrategyMoverIzquierda::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStrategyMoverIzquierda::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AStrategyMoverIzquierda::Mover(AGalaga_usfx_lab2Pawn* Pawn, float DeltaTime)
{
	// Verificar si el Pawn es válido
	if (Pawn)
	{
		// Teletransportar el Pawn al borde izquierdo
		Pawn->SetActorLocation(FVector(Pawn->GetActorLocation().X, 1600.0f, Pawn->GetActorLocation().Z));

		// Llamar a la función para restablecer el movimiento después del teletransporte
		Pawn->ResetMovementAfterTeleport();
	}
}

