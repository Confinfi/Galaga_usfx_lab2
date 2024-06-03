// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaProton.h"

ANaveEnemigaProton::ANaveEnemigaProton()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_3.TwinStickUFO_3'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaProton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}