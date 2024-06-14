// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "INaveEddyStates.h"
#include "IOriginator.h"
#include "MementoNaveEddy.h"
#include "NaveEddy.generated.h"
UCLASS()
class GALAGA_USFX_LAB2_API ANaveEddy : public AActor, public IIOriginator
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Reloj, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* MallaEddy;
public:	
	// Sets default values for this actor's properties
	ANaveEddy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	void RecibirDanio();
	bool bEstadoMolestoCambiado;
	int vida;
	void InicializarEstadosEddy(FString _estados);

	IINaveEddyStates* EstadoPacifico;
	IINaveEddyStates* EstadoMolesto;
	IINaveEddyStates* EstadoTraicion;
	IINaveEddyStates* EstadoExterminio;
	IINaveEddyStates* Estado;

	FORCEINLINE void EstablecerEstado(IINaveEddyStates* _estado);

	void EddyPacifico();
	void EddyMolesto();
	void EddyTraicion();
	void EddyExterminio();

	FORCEINLINE FString ObtenerEstadoActual();

	FORCEINLINE IINaveEddyStates* ObtenerEstadoPacifico();
	FORCEINLINE IINaveEddyStates* ObtenerEstadoMolesto();
	FORCEINLINE IINaveEddyStates* ObtenerEstadoTraicion();
	FORCEINLINE IINaveEddyStates* ObtenerEstadoExterminio();
	FORCEINLINE IINaveEddyStates* ObtenerEstado();

public:
	virtual TScriptInterface<IIMemento> CreateMemento() const override;
	virtual void RestoreFromMemento(const TScriptInterface<IIMemento>& Memento) override;

private:
	TArray<TScriptInterface<IIMemento>> StateHistory;

	void SaveState();
};
