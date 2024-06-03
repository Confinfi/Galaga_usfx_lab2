// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Galaga_usfx_lab2GameMode.generated.h"

UCLASS(MinimalAPI)
class AGalaga_usfx_lab2GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGalaga_usfx_lab2GameMode();

private:

	//class IBuilderNaveNodriza* NaveNodrizaEscudo;
	UPROPERTY(VisibleAnywhere, Category = "NaveEscudo")
	class ABuilderNaveBoss* NaveBoss;
	UPROPERTY(VisibleAnywhere, Category = "Director")
	class ADirectorNaveBoss* Director;
public:
	virtual void BeginPlay() override;
public:
	class ANaveEddy* NaveEddy;
};



