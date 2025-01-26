// Fill out your copyright notice in the Description page of Project Settings.

#include "DrownedGameSubsystem.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UDrownedGameSubsystem::CollectPopTab()
{
	PopTabCount++;
	PoptabsCountChangedEvent.Broadcast(PopTabCount);
}

// -----------------------------------------------------------------------------

int UDrownedGameSubsystem::GetPopTabCount()
{
	return PopTabCount;
}

// -----------------------------------------------------------------------------

void UDrownedGameSubsystem::SpendPopTabs(int Amount)
{
	PopTabCount = PopTabCount >= Amount ? PopTabCount - Amount : 0;
	PoptabsCountChangedEvent.Broadcast(PopTabCount);
}

// -----------------------------------------------------------------------------