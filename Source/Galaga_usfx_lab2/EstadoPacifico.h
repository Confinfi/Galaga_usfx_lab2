// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEddyStates.h"
#include "EstadoPacifico.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API AEstadoPacifico : public AActor, public IINaveEddyStates
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoPacifico();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(VisibleAnywhere, Category = "Estado Pacifico")
	class ANaveEddy* Eddy;
public:

	void EstablecerNave(class ANaveEddy* _eddy) override;
	void Mover(float Deltatime) override;
	FORCEINLINE FString ObtenerEstado() override;
	void Pacifico() override;

private:
	void Molesto() override {};
	void Traicion() override {};
	void Exterminio() override {};
	int DireccionMovimientoHorizontal = 1;
	float MovimientoNaves = 4;
	float limiteInferiorY = 1600.0f;


};
