// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.h"
#include "Fabrica.h"
#include "Facade.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API AFacade : public AActor
{GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFacade();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	UFUNCTION(BlueprintCallable, Category = "Naves Enemigas")
	static void SpawnNavesEnemigas(UWorld* World);

private:
	static void SpawnNaveEnemiga(FString TipoNave, UWorld* World, const FVector& SpawnLocation, const FRotator& SpawnRotation);

};
