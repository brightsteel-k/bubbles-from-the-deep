// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Enemies/Public/DrossSiegeSusbystem.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UDrossSiegeSusbystem::StartSiege()
{
	
}

// -----------------------------------------------------------------------------

void UDrossSiegeSusbystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

// -----------------------------------------------------------------------------

void UDrossSiegeSusbystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

void UDrossSiegeSusbystem::Deinitialize()
{
	Super::Deinitialize();
}

// -----------------------------------------------------------------------------

TStatId UDrossSiegeSusbystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UDrossSiegeSusbystem, STATGROUP_Tickables);
}
