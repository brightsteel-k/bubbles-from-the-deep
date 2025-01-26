// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "DrossSiegeSusbystem.generated.h"

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

/**
 * Controller that runs dross monster waves
 */
UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API UDrossSiegeSusbystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable)
	void StartSiege();
	
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	virtual void Deinitialize() override;
	virtual TStatId GetStatId() const override;
};
