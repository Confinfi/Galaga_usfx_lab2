// Fill out your copyright notice in the Description page of Project Settings.


#include "EstadoPacifico.h"
#include "NaveEddy.h"

// Sets default values
AEstadoPacifico::AEstadoPacifico()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEstadoPacifico::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEstadoPacifico::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEstadoPacifico::EstablecerNave(ANaveEddy* _eddy)
{
	Eddy = Cast<ANaveEddy>(_eddy);
}

void AEstadoPacifico::Mover(float Deltatime)
{
    if (Eddy)
    {
 
        FVector PosicionActual = Eddy->GetActorLocation();

   
        float LimiteDerecho = 1600.0f;
        float LimiteIzquierdo = -1600.0f;


        float VelocidadHorizontal = 1000.0f;

  
        float DesplazamientoHorizontal = VelocidadHorizontal * Deltatime;

        if (DireccionMovimientoHorizontal == 1) // Movimiento hacia derecha
        {
            FVector NuevaPosicion = PosicionActual + FVector(0.0f, DesplazamientoHorizontal, 0.0f);
            if (NuevaPosicion.Y <= LimiteDerecho)
            {
                Eddy->SetActorLocation(NuevaPosicion);
            }
            else
            {
                DireccionMovimientoHorizontal = -1;
            }
        }
        else // Movimiento hacia izquierda
        {
  
            FVector NuevaPosicion = PosicionActual - FVector(0.0f, DesplazamientoHorizontal, 0.0f);
            if (NuevaPosicion.Y >= LimiteIzquierdo)
            {
                Eddy->SetActorLocation(NuevaPosicion);
            }
            else
            {

                DireccionMovimientoHorizontal = 1;
            }
        }
    }
}

FString AEstadoPacifico::ObtenerEstado()
{
	return "Pacifico";
}

void AEstadoPacifico::Pacifico()
{
	UE_LOG(LogTemp, Warning, TEXT("Eddy esta en estado Pacifico"));
}