// Fill out your copyright notice in the Description page of Project Settings.


#include "EscudoNaveBoss.h"

// Sets default values
AEscudoNaveBoss::AEscudoNaveBoss()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallav(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Trim_90_In.Shape_Trim_90_In'"));
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(RootComponent);
	MeshComp->SetStaticMesh(mallav.Object);
	RootComponent = MeshComp;

	SetActorScale3D(FVector(3.5f, 3.5f, 3.5f)); //escala del escudo
}

// Called when the game starts or when spawned
void AEscudoNaveBoss::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEscudoNaveBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

