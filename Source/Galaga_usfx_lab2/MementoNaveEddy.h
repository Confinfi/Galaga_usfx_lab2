// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IMemento.h"
#include "MementoNaveEddy.generated.h"

UCLASS()
class GALAGA_USFX_LAB2_API AMementoNaveEddy : public AActor, public IIMemento
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMementoNaveEddy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	float vida;

	virtual float Getvida() const override {
		return vida;
	}
};
