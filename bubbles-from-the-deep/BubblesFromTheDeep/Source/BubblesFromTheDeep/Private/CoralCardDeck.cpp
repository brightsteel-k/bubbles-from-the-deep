// Fill out your copyright notice in the Description page of Project Settings.


#include "CoralCardDeck.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UCoralCardDeck::GetDeck(TArray<UCoralCard*>& DeckOut)
{
	DeckOut.Empty(Deck.Num());
	for (UCoralCard * Card : Deck) {
		DeckOut.Add(Card);
	}
}

// -----------------------------------------------------------------------------
