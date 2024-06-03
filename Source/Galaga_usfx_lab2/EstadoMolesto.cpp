// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoMolesto.h"
#include "NaveEddy.h"

// Sets default values
AEstadoMolesto::AEstadoMolesto()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoMolesto::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoMolesto::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoMolesto::EstablecerNave(ANaveEddy* _eddy)
{
	Eddy = Cast<ANaveEddy>(_eddy);
}

void AEstadoMolesto::Mover(float DeltaTime)
{
    if (Eddy)
    {
        FVector PosicionActual = Eddy->GetActorLocation();
        float VelocidadVertical = 1000.0f;
        float DesplazamientoVertical = VelocidadVertical * DeltaTime;

        if (DireccionMovimientoVertical == 1) // Movimiento hacia arriba
        {
            float LimiteSuperior = 1600.0f;
            FVector NuevaPosicion = PosicionActual + FVector(DesplazamientoVertical, 0.0f, 0.0f);
            if (NuevaPosicion.X <= LimiteSuperior)
            {
                Eddy->SetActorLocation(NuevaPosicion);
            }
            else
            {
                DireccionMovimientoVertical = -1;
            }
        }
        else // Movimiento hacia abajo
        {
            float LimiteInferior = -1600.0f;
            FVector NuevaPosicion = PosicionActual - FVector(DesplazamientoVertical, 0.0f, 0.0f);
            if (NuevaPosicion.X >= LimiteInferior)
            {
                Eddy->SetActorLocation(NuevaPosicion);
            }
            else
            {
                DireccionMovimientoVertical = 1;
            }
        }
    }
}

FString AEstadoMolesto::ObtenerEstado()
{
	return "Estado Molesto";
}

void AEstadoMolesto::Molesto()
{
	UE_LOG(LogTemp, Warning, TEXT("Eddy se encuentra en estado Molesto"));
}