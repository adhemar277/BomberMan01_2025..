// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Enemigo.h"
#include "EnemigoSubterraneo.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API AEnemigoSubterraneo : public AEnemigo
{
	GENERATED_BODY()

public:
	// Constructor
	AEnemigoSubterraneo();

protected:
	// Llamado cuando el juego comienza o cuando se genera
	virtual void BeginPlay() override;

public:
	// Llamado cada cuadro
	virtual void Tick(float DeltaTime) override;

private:
	// Direcci�n de movimiento del enemigo
	FVector MovimientoDireccion;

	// Velocidad de rotaci�n del enemigo
	float VelocidadRotacion;

	// Verificar si hay un obst�culo en la direcci�n dada
	bool HayObstaculoEnDireccion(FVector Direccion);

	// Teletransportar al enemigo
	void Teletransportar();

	// Detener el movimiento del enemigo
	void Detener();

	// Reanudar el movimiento del enemigo
	void Reanudar();

	// Verificar si la posici�n est� dentro de los l�mites del mapa


	// Temporizador para la teletransportaci�n
	FTimerHandle TemporizadorTeletransportacion;

	// Temporizador para la detenci�n
	FTimerHandle TemporizadorDetencion;

	// Bandera para indicar si el enemigo est� detenido
	bool bEstaDetenido;

	// L�mites del mapa
	FVector LimiteInferior;
	FVector LimiteSuperior;
};
