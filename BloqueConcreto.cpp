// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueConcreto.h"

ABloqueConcreto::ABloqueConcreto()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Concrete_Tiles.M_Concrete_Tiles'"));
		if (MaterialBase.Succeeded())
		{
			MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
		}
	}
  
	// Establecer valores predeterminados
    PrimaryActorTick.bCanEverTick = true; // Habilitar Tick()

        AmplitudMovimiento = 50.0f; // Altura máxima que sube y baja
        VelocidadMovimiento = 2.0f; // Velocidad del movimiento
}

    void ABloqueConcreto::BeginPlay()
    {
        Super::BeginPlay();
        PosicionInicial = GetActorLocation(); // Guardar la posición inicial
    }

    void ABloqueConcreto::Tick(float DeltaTime)
    {
        Super::Tick(DeltaTime);

        // Calcular nueva posición usando una onda seno
        float Desplazamiento = FMath::Sin(GetWorld()->GetTimeSeconds() * VelocidadMovimiento) * AmplitudMovimiento;
        FVector NuevaPosicion = PosicionInicial + FVector(0.0f, 0.0f, Desplazamiento);

        SetActorLocation(NuevaPosicion);
    }