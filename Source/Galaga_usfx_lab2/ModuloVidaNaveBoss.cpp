// Fill out your copyright notice in the Description page of Project Settings.


#include "ModuloVidaNaveBoss.h"

// Sets default values
AModuloVidaNaveBoss::AModuloVidaNaveBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallav(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_6.TwinStickUFO_6'"));
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComponent->SetupAttachment(RootComponent);
	MeshComponent->SetStaticMesh(mallav.Object);
	RootComponent = MeshComponent;

	SetActorScale3D(FVector(2.5f, 2.5f, 2.5f));
}

// Called when the game starts or when spawned
void AModuloVidaNaveBoss::BeginPlay()
{
	Super::BeginPlay();
	
	Impactosrecibidos = 0;
}

// Called every frame
void AModuloVidaNaveBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AModuloVidaNaveBoss::ImpactoProyectil()
{
	Impactosrecibidos++;
	if (Impactosrecibidos == 3)
	{
		Destroy();
	}
}
