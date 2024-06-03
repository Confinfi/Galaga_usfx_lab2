// Fill out your copyright notice in the Description page of Project Settings.


#include "Facade.h"
#include "NaveEnemiga.h"
#include "Fabrica.h"


// Sets default values
AFacade::AFacade()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFacade::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFacade::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFacade::SpawnNavesEnemigas(UWorld* World)
{
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("El mundo es nulo."));
        return;
    }

    const FVector ubicacionesIniciales[] = {
        FVector(1000.0f, -450.0f, 200.0f),
        FVector(700.0f, -300.0f, 200.0f),
        FVector(700.0f, -550.0f, 200.0f),
        FVector(100.0f, 450.0f, 200.0f),
        FVector(-200.0f, 700.0f, 200.0f),
        FVector(1000.0f, -700.0f, 200.0f)
    };

    const FRotator rotaciones[] = {
        FRotator(0.0f, 180.0f, 0.0f),
        FRotator(0.0f, 180.0f, 0.0f),
        FRotator(0.0f, 180.0f, 0.0f),
        FRotator(0.0f, 180.0f, 0.0f),
        FRotator(0.0f, 180.0f, 0.0f),
        FRotator(0.0f, 180.0f, 0.0f)
    };

    const FString tiposNaves[] = {
        "Slime",
        "Transporte",
        "Proton",
        "Espia",
        "Caza"
    };

    for (int32 i = 0; i < 4; ++i)
    {
        SpawnNaveEnemiga(tiposNaves[i], World, ubicacionesIniciales[i], rotaciones[i]);
    }
}

void AFacade::SpawnNaveEnemiga(FString TipoNave, UWorld* World, const FVector& SpawnLocation, const FRotator& SpawnRotation)
{
    if (!World)
    {
        UE_LOG(LogTemp, Error, TEXT("El mundo es nulo."));
        return;
    }

    ANaveEnemiga* NuevaNave = AFabrica::FabricaNaves(TipoNave, World, SpawnLocation, SpawnRotation);
    if (NuevaNave)
    {
        // Realizar acciones adicionales si es necesario
        // Por ejemplo, añadir la nave a una lista de naves enemigas
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Error al spawnear la nave enemiga de tipo: %s"), *TipoNave);
    }
}
