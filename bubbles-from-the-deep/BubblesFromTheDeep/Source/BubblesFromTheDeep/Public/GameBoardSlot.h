// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameBoardSlot.generated.h"


// -----------------------------------------------------------------------------
// Forward Declarations
// -----------------------------------------------------------------------------

class AGameBoard;
class ACoralTurret;

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API AGameBoardSlot : public AActor
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintReadOnly)
	AGameBoard* ParentGameBoard;
	
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable)
	void PlaceTurret(TSubclassOf<ACoralTurret> TurretClass);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ACoralTurret* GetTurret();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasTurret();

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void OnTurretPlaced();
	
	UFUNCTION(BlueprintNativeEvent)
	void OnTurretCleared();
	void OnTurretCleared_Implementation();

	UFUNCTION(BlueprintNativeEvent)
	void Initialize(AGameBoard* ParentBoard);
	virtual void Initialize_Implementation(AGameBoard* ParentBoard);
	
	// Sets default values for this actor's properties
	AGameBoardSlot();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------
	
	UPROPERTY(BlueprintReadWrite)
	ACoralTurret* SocketedTurret;

	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
