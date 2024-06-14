// Fill out your copyright notice in the Description page of Project Settings.


#include "NaveEddy.h"
#include "Galaga_usfx_lab2Projectile.h"
#include "EstadoPacifico.h"
#include "EstadoMolesto.h"
#include "EstadoTraicion.h"
#include "EstadoExterminio.h"
#include "INaveEddyStates.h"

// Sets default values
ANaveEddy::ANaveEddy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	static ConstructorHelpers::FObjectFinder<UStaticMesh> mallaEddy(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickUFO_8.TwinStickUFO_8'"));
	MallaEddy = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaAliada"));
	RootComponent = MallaEddy;
	MallaEddy->SetStaticMesh(mallaEddy.Object);
	MallaEddy->SetWorldScale3D(FVector(2.0f, 2.0f, 2.0f));
}

// Called when the game starts or when spawned
void ANaveEddy::BeginPlay()
{
	Super::BeginPlay();
	
	InicializarEstadosEddy("Estado_Pacifico");

	vida = 40.0f;
}

// Called every frame
void ANaveEddy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Estado)
	{
		Estado->Mover(DeltaTime);
	}
}

void ANaveEddy::RecibirDanio()
{
	vida -= 1.0f;
	if (vida <= 0.0f)
	{
		Destroy();
		FString Message = FString::Printf(TEXT("A mimir Eddy"));
		GEngine->AddOnScreenDebugMessage(-1, 3.f, FColor::Red, Message, true, FVector2D(2.0f, 2.0f));
	}
	else if (vida == 30.0f)
	{
		// Cambiar a estado Traicion
		InicializarEstadosEddy("Estado_Traicion");
	}
	else if (vida == 20.0f)
	{
		// Cambiar a estado Exterminio
		InicializarEstadosEddy("Estado_Molesto");
	}
	else if (vida == 10.0f)
	{
		// Cambiar a estado Molesto
		InicializarEstadosEddy("Estado_Exterminio");
	}
}

void ANaveEddy::InicializarEstadosEddy(FString _estados)
{
	if (_estados.Equals("Estado_Pacifico")) {
		EstadoPacifico = GetWorld()->SpawnActor<AEstadoPacifico>(AEstadoPacifico::StaticClass());
		EstadoPacifico->EstablecerNave(this);
		EstablecerEstado(EstadoPacifico);
	}
	if (_estados.Equals("Estado_Molesto")) {
		EstadoMolesto = GetWorld()->SpawnActor<AEstadoMolesto>(AEstadoMolesto::StaticClass());
		EstadoMolesto->EstablecerNave(this);
		EstablecerEstado(EstadoMolesto);
	}
	if (_estados.Equals("Estado_Traicion")) {
		EstadoTraicion = GetWorld()->SpawnActor<AEstadoTraicion>(AEstadoTraicion::StaticClass());
		EstadoTraicion->EstablecerNave(this);
		EstablecerEstado(EstadoTraicion);
	}
	if (_estados.Equals("Estado_Exterminio")) {
		EstadoExterminio = GetWorld()->SpawnActor<AEstadoExterminio>(AEstadoExterminio::StaticClass());
		EstadoExterminio->EstablecerNave(this);
		EstablecerEstado(EstadoExterminio);
	}
}

void ANaveEddy::EstablecerEstado(IINaveEddyStates* _estado)
{
	Estado = _estado;
}

void ANaveEddy::EddyPacifico()
{
	Estado->Pacifico();
}

void ANaveEddy::EddyMolesto()
{
	Estado->Molesto();
}

void ANaveEddy::EddyTraicion()
{
	Estado->Traicion();
}

void ANaveEddy::EddyExterminio()
{
	Estado->Exterminio();
}


IINaveEddyStates* ANaveEddy::ObtenerEstadoPacifico()
{
	return EstadoPacifico;
}

IINaveEddyStates* ANaveEddy::ObtenerEstadoMolesto()
{
	return EstadoMolesto;
}

IINaveEddyStates* ANaveEddy::ObtenerEstadoTraicion()
{
	return EstadoTraicion;
}

IINaveEddyStates* ANaveEddy::ObtenerEstadoExterminio()
{
	return EstadoExterminio;
}

IINaveEddyStates* ANaveEddy::ObtenerEstado()
{
	return Estado;
}

FString ANaveEddy::ObtenerEstadoActual()
{
	if (Estado) {
		return "El estado actual del jugador es: " + Estado->ObtenerEstado();
	}
	else {
		return "Estado no inicializado";
	}
}

TScriptInterface<IIMemento> ANaveEddy::CreateMemento() const
{
	AMementoNaveEddy* NewMemento = NewObject<AMementoNaveEddy>();
	NewMemento->vida = vida;
	return TScriptInterface<IIMemento>(NewMemento);
}

void ANaveEddy::RestoreFromMemento(const TScriptInterface<IIMemento>& Memento)
{
	if (Memento.GetObject())
	{
		vida = Memento->Getvida();
	}
}

void ANaveEddy::SaveState()
{
	StateHistory.Add(CreateMemento());
}