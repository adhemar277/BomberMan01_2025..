#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.h"
#include "Enemigo.h"
#include "Bomba.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABomba : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABomba();

protected:
    // Componente de malla est�tica
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Componentes")
    UStaticMeshComponent* MallaBomba;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


    // Radio de explosi�n
    UPROPERTY(EditAnywhere, Category = "Bomba")
    float RadioExplosion = 300.0f;

    // Tiempo para detonar la bomba
    UPROPERTY(EditAnywhere, Category = "Bomba")
    float TiempoDetonacion = 2.0f;

    // Referencias a los objetos en el mundo
    UPROPERTY(EditAnywhere, Category = "Bomba")
    TArray<ABloque*> Bloques;

    UPROPERTY(EditAnywhere, Category = "Bomba")
    TArray<AEnemigo*> Enemigos;

private:
    // Funci�n que realiza la explosi�n
    void Detonar();

    FTimerHandle TimerHandleExplosion;
};
