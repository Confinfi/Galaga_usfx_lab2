// Fill out your copyright notice in the Description page of Project Settings.


#include "StrategyMoverIzquierda.h"

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

