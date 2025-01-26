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
	void SetSocketedTurret(ACoralTurret* NewTurret);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	ACoralTurret* GetSocketedTurret();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasSocketedTurret();

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
