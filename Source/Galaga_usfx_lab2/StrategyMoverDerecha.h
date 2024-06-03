// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IStrategyPawn.h"
#include "StrategyMoverDerecha.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API AStrategyMoverDerecha : public AActor, public IIStrategyPawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStrategyMoverDerecha();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	virtual void Mover(AGalaga_usfx_lab2Pawn* Pawn, float DeltaTime) override;

};
