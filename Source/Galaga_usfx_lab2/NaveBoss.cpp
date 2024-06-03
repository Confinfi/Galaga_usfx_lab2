// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveBoss.h"
#include "ArmaNaveBoss.h"
#include "EscudoNaveBoss.h"
#include "ModuloVidaNaveBoss.h"

// Sets default values
ANaveBoss::ANaveBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANaveBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANaveBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void ANaveBoss::SetArmaNaveBoss(AArmaNaveBoss* arma)
{
	Arma = arma;
}
void ANaveBoss::SetEscudoNaveBoss(AEscudoNaveBoss* escudo)
{
	Escudo = escudo;
}
void ANaveBoss::SetModuloVidaNaveBoss(AModuloVidaNaveBoss* moduloVida)
{
	ModuloVida = moduloVida;
}

