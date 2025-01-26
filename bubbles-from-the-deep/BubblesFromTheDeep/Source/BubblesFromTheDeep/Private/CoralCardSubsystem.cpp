// Fill out your copyright notice in the Description page of Project Settings.

#include "CoralCardSubsystem.h"

#include "DrownedGameSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UCoralCardSubsystem::LoadDeck(UCoralCardDeck* Deck)
{
	Deck->GetDeck(CurrentDeck);
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::StartRound()
{
	
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::DrawCard()
{
	int DrawIndex = UKismetMathLibrary::RandomInteger(CurrentDeck.Num() - 1);
	UCoralCard* DrawnCard = CurrentDeck[DrawIndex];
	CurrentDeck.RemoveAt(DrawIndex);
	CurrentHand.Add(DrawnCard);
	DrawCardEvent.Broadcast(DrawnCard);
}

// -----------------------------------------------------------------------------

bool UCoralCardSubsystem::CanPlayCard(UCoralCard* Card)
{
	return UGameplayStatics::GetGameInstance(this)->
		GetSubsystem<UDrownedGameSubsystem>()->GetPopTabCount() >= Card->Cost;
}

// -----------------------------------------------------------------------------

void UCoralCardSubsystem::PlayCard(UCoralCard* Card)
{
	UGameplayStatics::GetGameInstance(this)->
		GetSubsystem<UDrownedGameSubsystem>()->SpendPopTabs(Card->Cost);
	CurrentHand.Remove(Card);
}

// -----------------------------------------------------------------------------
