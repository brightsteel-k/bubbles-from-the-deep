// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "DrownedGameSubsystem.generated.h"

// -----------------------------------------------------------------------------
// Delegate Definitions
// -----------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPoptabsCountChanged, int, PoptabsCount);

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

/**
 * 
 */
UCLASS()
class BUBBLESFROMTHEDEEP_API UDrownedGameSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FPoptabsCountChanged PoptabsCountChangedEvent;
	
	UPROPERTY(BlueprintReadWrite)
	int PopTabCount;

	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable)
	void CollectPopTab();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetPopTabCount();

	UFUNCTION(BlueprintCallable)
	void SpendPopTabs(int Amount);
};
