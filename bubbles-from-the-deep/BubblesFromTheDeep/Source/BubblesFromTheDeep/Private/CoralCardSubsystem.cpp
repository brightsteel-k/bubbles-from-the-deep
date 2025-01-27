// Fill out your copyright notice in the Description page of Project Settings.

#include "CoralCardSubsystem.h"

#include "DrownedGameSubsystem.h"
#include "BubblesFromTheDeep/Enemies/Public/DrossSiegeSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UCoralCardSubsystem::LoadDeck(UCoralCardDeck* Deck)
{
	Deck->GetDeck(CurrentDeck);
	DeckSizeChangeEvent.Broadcast(CurrentDeck.Num());

	// Starter hand
	CurrentHand.Add(HeartCard);
	DrawCardEvent.Broadcast(HeartCard);
	DeckSizeChangeEvent.Broadcast(CurrentDeck.Num());
	
	for (int i = 0; i < StartingHandSize - 1; i++) {
		int DrawIndex = UKismetMathLibrary::RandomInteger(CurrentDeck.Num() - 1);
		UCoralCard* DrawnCard = CurrentDeck[DrawIndex];
		// CurrentDeck.RemoveAt(DrawIndex);
		CurrentHand.Add(DrawnCard);
		DrawCardEvent.Broadcast(DrawnCard);
		DeckSizeChangeEvent.Broadcast(CurrentDeck.Num());
	}
	
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::StartRound()
{
	// Start card pickup loop
	FTimerHandle TimerHandle;
	float Delay = UKismetMathLibrary::RandomFloatInRange(DrawDelayRangeSeconds.Min, DrawDelayRangeSeconds.Max);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UCoralCardSubsystem::DrawCard, Delay);
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::DrawCard()
{
	if (CurrentHand.Num() < MaxHandSize) {
		int DrawIndex = UKismetMathLibrary::RandomInteger(CurrentDeck.Num() - 1);
		UCoralCard* DrawnCard = CurrentDeck[DrawIndex];
		// CurrentDeck.RemoveAt(DrawIndex);
		CurrentHand.Add(DrawnCard);
		DrawCardEvent.Broadcast(DrawnCard);
		DeckSizeChangeEvent.Broadcast(CurrentDeck.Num());
	}
	
	FTimerHandle TimerHandle;
	float Delay = UKismetMathLibrary::RandomFloatInRange(DrawDelayRangeSeconds.Min, DrawDelayRangeSeconds.Max);
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &UCoralCardSubsystem::DrawCard, Delay);
}

// -----------------------------------------------------------------------------

bool UCoralCardSubsystem::CanPlaySelectedCard()
{
	if (!HasSelectedCard()) {
		return false;
	}
	return UGameplayStatics::GetGameInstance(this)->
		GetSubsystem<UDrownedGameSubsystem>()->GetPopTabCount() >= SelectedCard->Cost;
}

// -----------------------------------------------------------------------------

UCoralCard* UCoralCardSubsystem::PlaySelectedCard()
{
	UGameplayStatics::GetGameInstance(this)->
		GetSubsystem<UDrownedGameSubsystem>()->SpendPopTabs(SelectedCard->Cost);
	CurrentHand.RemoveSingle(SelectedCard);
	
	UCoralCard* PlayedCard = SelectedCard;
	ClearSelectedCard();
	CardPlayedEvent.Broadcast(PlayedCard);
	return PlayedCard;
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::SetSelectedCard(UCoralCard* Card)
{
	SelectedCard = Card;
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::ClearSelectedCard()
{
	SelectedCard = nullptr;
}

// -----------------------------------------------------------------------------

UCoralCard* UCoralCardSubsystem::GetSelectedCard()
{
	return SelectedCard;
}

// -----------------------------------------------------------------------------

bool UCoralCardSubsystem::HasSelectedCard()
{
	return SelectedCard != nullptr;
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

// -----------------------------------------------------------------------------

TStatId UCoralCardSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UCoralCardSubsystem, STATGROUP_Tickables);
}

// -----------------------------------------------------------------------------
