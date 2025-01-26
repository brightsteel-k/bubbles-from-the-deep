// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoralCard.h"
#include "CoralCardDeck.h"
#include "DrownedGameSubsystem.h"
#include "Subsystems/WorldSubsystem.h"
#include "CoralCardSubsystem.generated.h"

// -----------------------------------------------------------------------------
// Delegate Definitions
// -----------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoralCardSubsystemDrawEvent, UCoralCard*, Card);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoralCardDeckSizeChange, int, NewDeckSize);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCoralCardPlayedEvent, UCoralCard*, Card);

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

/**
 * 
 */
UCLASS()
class BUBBLESFROMTHEDEEP_API UCoralCardSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int StartingHandSize = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxHandSize = 6;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FCoralCardSubsystemDrawEvent DrawCardEvent;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FCoralCardDeckSizeChange DeckSizeChangeEvent;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FCoralCardPlayedEvent CardPlayedEvent;
	
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	virtual void Deinitialize() override;
	virtual TStatId GetStatId() const override;

	UFUNCTION(BlueprintCallable)
	void LoadDeck(UCoralCardDeck* Deck);

	UFUNCTION(BlueprintCallable)
	void StartRound();

	UFUNCTION(BlueprintCallable)
	void DrawCard();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanPlaySelectedCard();

	UFUNCTION(BlueprintCallable)
	UCoralCard* PlaySelectedCard();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	UCoralCard* GetSelectedCard();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool HasSelectedCard();

	UFUNCTION(BlueprintCallable)
	void SetSelectedCard(UCoralCard* Card);

	UFUNCTION(BlueprintCallable)
	void ClearSelectedCard();

protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UCoralCard*> CurrentDeck;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<UCoralCard*> CurrentHand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCoralCard* SelectedCard = nullptr;
};
