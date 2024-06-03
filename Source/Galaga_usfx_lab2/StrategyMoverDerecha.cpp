#include "StrategyMoverDerecha.h"
#include "Galaga_usfx_lab2Pawn.h"

// Constructor
AStrategyMoverDerecha::AStrategyMoverDerecha()
{
	// Set this actor to call Tick() every frame
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AStrategyMoverDerecha::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AStrategyMoverDerecha::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Implementaci�n de la funci�n de mover hacia la izquierda
void AStrategyMoverDerecha::Mover(AGalaga_usfx_lab2Pawn* Pawn, float DeltaTime)
{
	// Verificar si el Pawn es v�lido
	if (Pawn)
	{
		// Teletransportar el Pawn al borde izquierdo
		Pawn->SetActorLocation(FVector( Pawn->GetActorLocation().X, -1600.0f, Pawn->GetActorLocation().Z));

		// Llamar a la funci�n para restablecer el movimiento despu�s del teletransporte
		Pawn->ResetMovementAfterTeleport();
	}
}