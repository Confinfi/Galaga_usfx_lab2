// Fill out your copyright notice in the Description page of Project Settings.


#include "Fabrica.h"
#include "NaveEnemigaCaza.h"
#include "NaveEnemigaEspia.h"
#include "NaveEnemigaTransporte.h"
#include "NaveEnemigaSlime.h"
#include "NaveEnemigaProton.h"

// Sets default values
AFabrica::AFabrica()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AFabrica::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFabrica::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

ANaveEnemiga* AFabrica::FabricaNaves (FString CrearNave, UWorld* World, FVector SpawnLocacion, FRotator SpawnRotacion)
{
	if (CrearNave == "Caza")
	{
		ANaveEnemigaCaza* NaveLista= World->SpawnActor<ANaveEnemigaCaza>(SpawnLocacion, SpawnRotacion);
		return NaveLista;
	}
	if (CrearNave == "Espia")
		{
		ANaveEnemigaEspia* NaveLista= World->SpawnActor<ANaveEnemigaEspia>(SpawnLocacion, SpawnRotacion);
			return NaveLista;
		}
	if (CrearNave == "Transporte")
		{
		ANaveEnemigaTransporte* NaveLista= World->SpawnActor<ANaveEnemigaTransporte>(SpawnLocacion, SpawnRotacion);
		return NaveLista;
		}
	if (CrearNave == "Slime")
		{
		ANaveEnemigaSlime* NaveLista= World->SpawnActor<ANaveEnemigaSlime>(SpawnLocacion, SpawnRotacion);
		return NaveLista;
		}
	if (CrearNave == "Proton")
		{
		ANaveEnemigaProton* NaveLista= World->SpawnActor<ANaveEnemigaProton>(SpawnLocacion, SpawnRotacion);
		return NaveLista;
	}

		return nullptr;
}

