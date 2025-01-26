// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CoralCardDeck.generated.h"

/**
 * A deck of coral cards
 */
UCLASS(BlueprintType)
class BUBBLESFROMTHEDEEP_API UCoralCardDeck : public UDataAsset
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UCoralCard*> Deck;

	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintPure)
	void GetDeck(TArray<UCoralCard*>& DeckOut);
	
};
