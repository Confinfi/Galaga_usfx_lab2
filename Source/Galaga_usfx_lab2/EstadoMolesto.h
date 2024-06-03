// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEddyStates.h"
#include "EstadoMolesto.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API AEstadoMolesto : public AActor, public IINaveEddyStates
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoMolesto();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(VisibleAnywhere, Category = "Estado Molesto")
	class ANaveEddy* Eddy;
public:
	void EstablecerNave(class ANaveEddy* _eddy);
	void Mover(float Deltatime);
	FORCEINLINE FString ObtenerEstado();
	void Molesto();
private:
	void Pacifico() {};
	void Traicion() {};
	void Exterminio() {};
	int DireccionMovimientoVertical = 1;
	float MovimientoNaves = 8;
	float limiteInferiorY = 1600.0f;
};
