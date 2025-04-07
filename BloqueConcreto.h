// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueConcreto.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueConcreto : public ABloque
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABloqueConcreto();

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float DeltaTime) override;

private:
    FVector PosicionInicial; // Posición inicial del bloque
    float AmplitudMovimiento; // Qué tan alto y bajo se mueve
    float VelocidadMovimiento; // Velocidad del movimiento
};
