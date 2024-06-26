// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscudoNaveBoss.generated.h"

UCLASS()
class GALAGA_USFX_LAB2_API AEscudoNaveBoss : public AActor
{
	GENERATED_BODY()
protected:
	UStaticMeshComponent* MeshComp;	
public:	
	// Sets default values for this actor's properties
	AEscudoNaveBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
