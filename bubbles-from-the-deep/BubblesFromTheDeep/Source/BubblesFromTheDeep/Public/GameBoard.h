// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameBoard.generated.h"

// -----------------------------------------------------------------------------
// Forward Declarations
// -----------------------------------------------------------------------------

class AGameBoardSlot;

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------
UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API AGameBoard : public AActor
{
	GENERATED_BODY()
	
public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	static AGameBoard* CurrentGameBoard;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<AGameBoardSlot*> GameBoardSlots;

	UPROPERTY(BlueprintReadWrite)
	AGameBoardSlot* TargetSlot;
	
	// Sets default values for this actor's properties
	AGameBoard();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable)
	AGameBoardSlot* GetTargetSlot();

	UFUNCTION(BlueprintCallable)
	void SetTargetSlot(AGameBoardSlot* Slot);

	UFUNCTION(BlueprintCallable)
	static AGameBoard* GetGameBoard();

	UFUNCTION(BlueprintCallable)
	static void SetCurrentGameBoard(AGameBoard* GameBoard);

	UFUNCTION(BlueprintCallable)
	static void ClearCurrentGameBoard();

protected:
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RegisterGameBoardSlots();

	UFUNCTION(BlueprintCallable)
	void RegisterGameBoardSlot(AGameBoardSlot* Slot);
};
