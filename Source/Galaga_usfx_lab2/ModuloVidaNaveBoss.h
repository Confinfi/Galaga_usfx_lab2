// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ModuloVidaNaveBoss.generated.h"

UCLASS()
class GALAGA_USFX_LAB2_API AModuloVidaNaveBoss : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	AModuloVidaNaveBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UStaticMeshComponent* MeshComponent;

	int Impactosrecibidos;
public:
	void ImpactoProyectil();
};
