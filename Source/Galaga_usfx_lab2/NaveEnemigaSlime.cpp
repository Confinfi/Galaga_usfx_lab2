// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEnemigaSlime.h"

ANaveEnemigaSlime::ANaveEnemigaSlime()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> malla(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_5.TwinStickUFO_5'"));
	mallaNaveEnemiga->SetStaticMesh(malla.Object);

	PrimaryActorTick.bCanEverTick = true;
}

void ANaveEnemigaSlime::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
