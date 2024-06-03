// Fill out your copyright notice in the Description page of Project Settings.


#include "ArmaNaveBoss.h"

// Sets default values
AArmaNaveBoss::AArmaNaveBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallav(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetStaticMesh(mallav.Object);
	RootComponent = MeshComp;

	
	SetActorScale3D(FVector(1.5f, 1.5f, 1.5f)); //escala del arma 
}

// Called when the game starts or when spawned
void AArmaNaveBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AArmaNaveBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

