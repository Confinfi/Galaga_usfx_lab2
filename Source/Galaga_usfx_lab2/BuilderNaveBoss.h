// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBuilderNaveBoss.h"
#include "BuilderNaveBoss.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API ABuilderNaveBoss : public AActor, public IIBuilderNaveBoss
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuilderNaveBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "NaveBoss")
	class ANaveBoss* NaveBoss;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:

	virtual void GetArmaNaveBoss() override;
	virtual void GetEscudoNaveBoss() override;
	virtual void GetModuloVidaNaveBoss() override;
	virtual class ANaveBoss* GetNaveBoss() override;


};
