// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "INaveEddyStates.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UINaveEddyStates : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class GALAGA_USFX_LAB2_API IINaveEddyStates
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual void EstablecerNave(class ANaveEddy* _eddy) = 0;
	virtual void Mover(float Deltatime) = 0;

	virtual void Pacifico() = 0;
	virtual void Molesto() = 0;
	virtual void Traicion() = 0;
	virtual void Exterminio() = 0;

	virtual FString ObtenerEstado() = 0;
};
