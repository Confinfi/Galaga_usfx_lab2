// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEddyStates.h"
#include "EstadoExterminio.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API AEstadoExterminio : public AActor, public IINaveEddyStates
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEstadoExterminio();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	UPROPERTY(VisibleAnywhere, Category = "Estado Exterminio")
	class ANaveEddy* Eddy;
public:
	void EstablecerNave(class ANaveEddy* _eddy);
	void Mover(float Deltatime);
	FORCEINLINE FString ObtenerEstado();
	void Exterminio();
	float TiempoTranscurrido = 0.0f;
private:
	void Pacifico() {};
	void Molesto() {};
	void Traicion() {};
	int DireccionMovimientoHorizontal = 1;
	float MovimientoNaves = 16;
	float limiteInferiorY = 1600.0f;
};
