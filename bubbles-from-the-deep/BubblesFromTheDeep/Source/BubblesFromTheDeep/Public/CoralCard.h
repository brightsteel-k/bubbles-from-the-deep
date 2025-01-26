// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoralTurret.h"
#include "Engine/DataAsset.h"
#include "CoralCard.generated.h"

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API UCoralCard : public UDataAsset
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Title;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(MultiLine=true))
	FText Description;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* CardTexture;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ACoralTurret> TurretClass;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Cost;
};
