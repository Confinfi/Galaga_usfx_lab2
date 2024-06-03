// Copyright Epic Games, Inc. All Rights Reserved.

#include "Galaga_usfx_lab2GameMode.h"
#include "Galaga_usfx_lab2Pawn.h"

AGalaga_usfx_lab2GameMode::AGalaga_usfx_lab2GameMode()
{
	// set default pawn class to our character class
	DefaultPawnClass = AGalaga_usfx_lab2Pawn::StaticClass();
}
