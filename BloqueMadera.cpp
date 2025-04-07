// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"

ABloqueMadera::ABloqueMadera()
{
    if (MallaBloque)
    {
        static ConstructorHelpers::FObjectFinder<UMaterial> MaterialBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));

        if (MaterialBase.Succeeded())
        {
            MallaBloque->SetMaterial(0, MaterialBase.Object); // Asignar el material al slot 0
        }
    }

	// Configuración del actor
    PrimaryActorTick.bCanEverTick = true; // Habilitar el Tick()

    AmplitudMovimiento = 100.0f; // Distancia que se mueve a la izquierda y derecha
    VelocidadMovimiento = 2.0f; // Velocidad del movimiento
}

void ABloqueMadera::BeginPlay()
{
    Super::BeginPlay();
    PosicionInicial = GetActorLocation(); // Guardar la posición inicial
}

void ABloqueMadera::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    // Movimiento en el eje X (izquierda-derecha) usando una onda seno
    float Desplazamiento = FMath::Sin(GetWorld()->GetTimeSeconds() * VelocidadMovimiento) * AmplitudMovimiento;
    FVector NuevaPosicion = PosicionInicial + FVector(Desplazamiento, 0.0f, 0.0f);

    SetActorLocation(NuevaPosicion);
}