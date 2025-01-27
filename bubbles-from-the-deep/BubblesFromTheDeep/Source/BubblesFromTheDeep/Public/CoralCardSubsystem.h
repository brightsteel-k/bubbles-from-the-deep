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
	int StartingHandSize = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxHandSize = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFloatInterval DrawDelayRangeSeconds = FFloatInterval(6.0f, 12.0f);

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FCoralCardSubsystemDrawEvent DrawCardEvent;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FCoralCardDeckSizeChange DeckSizeChangeEvent;

	UPROPERTY(BlueprintAssignable, BlueprintReadWrite, BlueprintCallable)
	FCoralCardPlayedEvent CardPlayedEvent;

	// To be initialized by an actor
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCoralCard* HeartCard;
	
	float LastDrawTime;
	
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
