// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoralTurret.generated.h"

// -----------------------------------------------------------------------------
// Forward Declaration
// -----------------------------------------------------------------------------

class AGameBoardSlot;

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------
UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API ACoralTurret : public AActor
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintReadOnly)
	bool bIsAlive = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
	
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void OnTurretPlaced(AGameBoardSlot* Slot);
	void OnTurretPlaced_Implementation(AGameBoardSlot* Slot);

	UFUNCTION(BlueprintCallable)
	AGameBoardSlot* GetOwningGameBoardSlot();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Die();
	void Die_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void TurretTakeDamage(float Damage);
	void TurretTakeDamage_Implementation(float Damage);
	
	// Sets default values for this actor's properties
	ACoralTurret();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------

	UPROPERTY()
	AGameBoardSlot* OwningGameBoardSlot;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
};
