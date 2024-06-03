// Fill out your copyright notice in the Description page of Project Settings.


#include "BuilderNaveBoss.h"
#include "NaveBoss.h"
#include "ArmaNaveBoss.h"
#include "EscudoNaveBoss.h"
#include "ModuloVidaNaveBoss.h"

// Sets default values
ABuilderNaveBoss::ABuilderNaveBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuilderNaveBoss::BeginPlay()
{
	Super::BeginPlay();
	
	NaveBoss = GetWorld()->SpawnActor<ANaveBoss>(ANaveBoss::StaticClass());
	NaveBoss->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void ABuilderNaveBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ABuilderNaveBoss::GetArmaNaveBoss()
{
	FVector Locacion = FVector(1880, -60, 200);
	FVector Locacion2 = FVector(1880, 300, 200);
	FRotator Rotacion = FRotator(0, 180, 0);

	Arma = GetWorld()->SpawnActor<AArmaNaveBoss>(AArmaNaveBoss::StaticClass(), Locacion, Rotacion);
	Arma = GetWorld()->SpawnActor<AArmaNaveBoss>(AArmaNaveBoss::StaticClass(), Locacion2, Rotacion);

	NaveBoss->SetArmaNaveBoss(Arma);
}
void ABuilderNaveBoss::GetEscudoNaveBoss()
{
	FVector Locacion = FVector(1680, 120, 200);
	FRotator Rotacion = FRotator(0, 225, 0);

	Escudo = GetWorld()->SpawnActor<AEscudoNaveBoss>(AEscudoNaveBoss::StaticClass(), Locacion, Rotacion);

	NaveBoss->SetEscudoNaveBoss(Escudo);
}
void ABuilderNaveBoss::GetModuloVidaNaveBoss()
{
	FVector Locacion = FVector(1800, 120, 200);
	FRotator Rotacion = FRotator(0, 180, 0);

	ModuloVida = GetWorld()->SpawnActor<AModuloVidaNaveBoss>(AModuloVidaNaveBoss::StaticClass(), Locacion, Rotacion);

	NaveBoss->SetModuloVidaNaveBoss(ModuloVida);
}
ANaveBoss* ABuilderNaveBoss::GetNaveBoss()
{
	return NaveBoss;
}
