// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderNaveBoss.h"
#include "DirectorNaveBoss.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API ADirectorNaveBoss : public AActor
{
	GENERATED_BODY()

private:
	IIBuilderNaveBoss* usarBuilder;
    
public:	
	// Sets default values for this actor's properties
	ADirectorNaveBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	void ConstruirNave();

	void SetBuilder(AActor* Builder);

	class ANaveBoss* GetNaveBoss();

};
