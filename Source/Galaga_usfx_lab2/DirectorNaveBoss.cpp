// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectorNaveBoss.h"

// Sets default values
ADirectorNaveBoss::ADirectorNaveBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectorNaveBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectorNaveBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirectorNaveBoss::ConstruirNave()
{
	if (usarBuilder)
	{
		usarBuilder->GetArmaNaveBoss();
		usarBuilder->GetEscudoNaveBoss();
		usarBuilder->GetModuloVidaNaveBoss();
	}
}

void ADirectorNaveBoss::SetBuilder(AActor* Builder)
{
	usarBuilder = Cast<IIBuilderNaveBoss>(Builder);
}

ANaveBoss* ADirectorNaveBoss::GetNaveBoss()
{
	if (usarBuilder)
	{
	return usarBuilder->GetNaveBoss();
	}
	else
	{
	return nullptr;
	}
}
