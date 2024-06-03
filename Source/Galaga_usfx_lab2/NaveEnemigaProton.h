// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaProton.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB2_API ANaveEnemigaProton : public ANaveEnemiga
{
	GENERATED_BODY()

public:
	ANaveEnemigaProton();

	FString NombreNave = "Proton";
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
