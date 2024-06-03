// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_usfx_lab2GameMode.h"
#include "Galaga_usfx_lab2Pawn.h"
#include "DirectorNaveBoss.h"
#include "BuilderNaveBoss.h"
#include "NaveBoss.h"
#include "ArmaNaveBoss.h"
#include "EscudoNaveBoss.h"
#include "ModuloVidaNaveBoss.h"
#include "NaveEddy.h"
#include "Facade.h"


AGalaga_usfx_lab2GameMode::AGalaga_usfx_lab2GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_usfx_lab2Pawn::StaticClass();
}
void AGalaga_usfx_lab2GameMode::BeginPlay()
{
	Super::BeginPlay();
	Director = GetWorld()->SpawnActor<ADirectorNaveBoss>(ADirectorNaveBoss::StaticClass());
	NaveBoss = GetWorld()->SpawnActor<ABuilderNaveBoss>(ABuilderNaveBoss::StaticClass());
	Director->SetBuilder(NaveBoss);
	Director->ConstruirNave();

	ANaveBoss* NuevaNaveBoss = Director->GetNaveBoss();

	FVector ubicacionNaveEstado = FVector(-570.0f, 0.0f, 200.0f);
	FRotator rotacionNaveEstado = FRotator(0.0f, 180.0f, 0.0f);

	NaveEddy = GetWorld()->SpawnActor<ANaveEddy>(ubicacionNaveEstado, rotacionNaveEstado);

	AFacade::SpawnNavesEnemigas(GetWorld());

}