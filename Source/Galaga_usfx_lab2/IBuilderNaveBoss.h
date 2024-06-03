// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBuilderNaveBoss.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UIBuilderNaveBoss : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_LAB2_API IIBuilderNaveBoss
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void GetArmaNaveBoss() = 0;
	virtual void GetEscudoNaveBoss() = 0;
	virtual void GetModuloVidaNaveBoss() = 0;
	virtual class ANaveBoss* GetNaveBoss() = 0;

	class AArmaNaveBoss* Arma;
	class AEscudoNaveBoss* Escudo;
	class AModuloVidaNaveBoss* ModuloVida;
};
