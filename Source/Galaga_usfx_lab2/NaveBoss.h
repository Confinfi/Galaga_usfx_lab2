// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IDirectorNaveBoss.h"
#include "NaveBoss.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API ANaveBoss : public AActor, public IIDirectorNaveBoss
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANaveBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	class AArmaNaveBoss* Arma;
	class AEscudoNaveBoss* Escudo;
	class AModuloVidaNaveBoss* ModuloVida;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	virtual void SetArmaNaveBoss(AArmaNaveBoss* arma) override;
	virtual void SetEscudoNaveBoss(AEscudoNaveBoss* escudo) override;
	virtual void SetModuloVidaNaveBoss(AModuloVidaNaveBoss* moduloVida) override;

};
