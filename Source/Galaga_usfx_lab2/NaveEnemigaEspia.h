// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveEnemiga.h"
#include "NaveEnemigaEspia.generated.h"

/**
 * 
 */
UCLASS()
class GALAGA_USFX_LAB2_API ANaveEnemigaEspia : public ANaveEnemiga
{
	GENERATED_BODY()

public:
	ANaveEnemigaEspia();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
