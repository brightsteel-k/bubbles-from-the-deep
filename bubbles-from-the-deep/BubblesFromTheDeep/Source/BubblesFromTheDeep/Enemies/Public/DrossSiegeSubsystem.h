// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrossMonster.h"
#include "Subsystems/WorldSubsystem.h"
#include "DrossSiegeSubsystem.generated.h"

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

/**
 * Controller that runs dross monster waves
 */
UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API UDrossSiegeSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY()
	TArray<ADrossMonster*> ActiveMonsters;
	
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	virtual void Deinitialize() override;
	virtual TStatId GetStatId() const override;

	UFUNCTION(BlueprintCallable)
	void StartSiege();

	UFUNCTION(BlueprintCallable)
	bool IsMonsterWithinRange(FVector WorldLocation, float Range, ADrossMonster*& ClosestMonster);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UPARAM(DisplayName="Count") int GetActiveMonsters(TArray<ADrossMonster*>& OutMonsters);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetNumActiveMonsters();
	
	UFUNCTION(BlueprintCallable)
	void OnDrossMonsterSpawned(ADrossMonster* DrossMonster);

	UFUNCTION(BlueprintCallable)
	void OnDrossMonsterKilled(ADrossMonster* DrossMonster);
};
