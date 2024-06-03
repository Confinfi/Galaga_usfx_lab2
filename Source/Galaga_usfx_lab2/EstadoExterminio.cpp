// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoExterminio.h"
#include "NaveEddy.h"

// Sets default values
AEstadoExterminio::AEstadoExterminio()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoExterminio::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoExterminio::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoExterminio::EstablecerNave(ANaveEddy* _eddy)
{
	Eddy = Cast<ANaveEddy>(_eddy);
}

void AEstadoExterminio::Mover(float DeltaTime)
{
    if (Eddy)
    {
        TiempoTranscurrido += DeltaTime;
        float Radio = 1000.0f; // Radio de la estrella
        float VelocidadAngular = 5.0f; // Velocidad angular

        // Calcular la posición de los vértices de la estrella
        float Angulo = TiempoTranscurrido * VelocidadAngular;
        float X = Radio * FMath::Cos(Angulo);
        float Y = Radio * FMath::Sin(Angulo);
        FVector NuevaPosicion = FVector(X, Y, Eddy->GetActorLocation().Z);

        Eddy->SetActorLocation(NuevaPosicion);
    }
}

FString AEstadoExterminio::ObtenerEstado()
{
	return "Exterminio";
}

void AEstadoExterminio::Exterminio()
{
	UE_LOG(LogTemp, Warning, TEXT("Eddy se encuentra en estado Traicion"));
}
