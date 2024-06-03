// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoTraicion.h"
#include "NaveEddy.h"

// Sets default values
AEstadoTraicion::AEstadoTraicion()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoTraicion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoTraicion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoTraicion::EstablecerNave(ANaveEddy* _eddy)
{
	Eddy = Cast<ANaveEddy>(_eddy);
}

void AEstadoTraicion::Mover(float DeltaTime)
{
    if (Eddy)
    {
        float Radio = 1000.0f; // Radio del círculo
        float VelocidadAngular = 1.5f; // Velocidad angular
        TiempoTranscurrido += DeltaTime;

        // Calcular la nueva posición en el círculo
        float X = Radio * FMath::Cos(VelocidadAngular * TiempoTranscurrido);
        float Y = Radio * FMath::Sin(VelocidadAngular * TiempoTranscurrido);
        FVector NuevaPosicion = FVector(X, Y, Eddy->GetActorLocation().Z);

        Eddy->SetActorLocation(NuevaPosicion);
    }
}

FString AEstadoTraicion::ObtenerEstado()
{
	return "Traicion";
}

void AEstadoTraicion::Traicion()
{
	UE_LOG(LogTemp, Warning, TEXT("Eddy se encuentra en estado Traicion"));
}

