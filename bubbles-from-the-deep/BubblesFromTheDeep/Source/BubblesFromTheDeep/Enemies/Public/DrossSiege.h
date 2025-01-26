// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DrossMonster.h"
#include "Engine/DataAsset.h"
#include "DrossSiege.generated.h"

// -----------------------------------------------------------------------------
// Struct Definition
// -----------------------------------------------------------------------------

USTRUCT(BlueprintType)
struct FDrossMonsterWave
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ADrossMonster> DrossMonsterClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FInt32Interval WaveSize = FInt32Interval(8, 10);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFloatInterval SpawnpointAngleRange = FFloatInterval(-180, 180);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float WaveDurationSeconds;
};

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

/**
 * A sequence of dross monster waves
 */
UCLASS(BlueprintType)
class BUBBLESFROMTHEDEEP_API UDrossSiege : public UDataAsset
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetDrossSiegeWaves(TArray<FDrossMonsterWave>& DrossSiegeWavesOut);
	
protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDrossMonsterWave> Waves;
};
