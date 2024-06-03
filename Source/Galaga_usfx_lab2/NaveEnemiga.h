// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NaveEnemiga.generated.h"

UCLASS(abstract)	// Abstract class
class GALAGA_USFX_LAB2_API ANaveEnemiga : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Projectile, meta = (AllowPrivateAccess = "true"))

	UStaticMeshComponent* mallaNaveEnemiga;

public:	
	// Sets default values for this actor's properties
	ANaveEnemiga();

protected:
	float Dano;
	float Vida;
	float Velocidad;
	FString Nombre;
	FVector Posicion;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
public:
	FORCEINLINE float GetDano() const { return Dano; }
	FORCEINLINE float GetVida() const { return Vida; }
	FORCEINLINE float GetVelocidad() const { return Velocidad; }
	FORCEINLINE FString GetNombre() const { return Nombre; }
	FORCEINLINE FVector GetPosicion() const { return Posicion; }

	FORCEINLINE void SetDano(float dano) { Dano = dano; }	
	FORCEINLINE void SetVida(float vida) { Vida = vida; }
	FORCEINLINE void SetVelocidad(float velocidad) { Velocidad = velocidad; }
	FORCEINLINE void SetNombre(FString nombre) { this->Nombre = nombre; }
	FORCEINLINE void SetPosicion(FVector posicion) { this->Posicion = posicion; }

};
