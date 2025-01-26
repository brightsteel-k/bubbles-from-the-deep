// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Enemies/Public/DrossSiegeSubsystem.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::StartSiege()
{
	
}

// -----------------------------------------------------------------------------

bool UDrossSiegeSubsystem::IsMonsterWithinRange(FVector WorldLocation, float Range, ADrossMonster*& ClosestMonster)
{
	float RangeSqr = Range * Range;
	float ClosestRangeSqr = FLT_MAX;
	bool MonsterFound = false;
	for (ADrossMonster* DrossMonster : ActiveMonsters) {
		float DistSqr = FVector::DistSquaredXY(WorldLocation, DrossMonster->GetActorLocation());
		if (DistSqr > RangeSqr) {
			 continue;
		}

		// Found a monster
		MonsterFound = true;
		if (DistSqr < ClosestRangeSqr) {
			ClosestMonster = DrossMonster;
			ClosestRangeSqr = DistSqr;
		}
	}
	
	return MonsterFound;
}

// -----------------------------------------------------------------------------

int UDrossSiegeSubsystem::GetActiveMonsters(TArray<ADrossMonster*>& OutMonsters)
{
	OutMonsters.Empty(ActiveMonsters.Num());
	for (ADrossMonster* Monster : ActiveMonsters) {
		OutMonsters.Add(Monster);
	}
	return OutMonsters.Num();
}

// -----------------------------------------------------------------------------

int UDrossSiegeSubsystem::GetNumActiveMonsters()
{
	return ActiveMonsters.Num();
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::OnDrossMonsterSpawned(ADrossMonster* DrossMonster)
{
	ActiveMonsters.Add(DrossMonster);	
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::OnDrossMonsterKilled(ADrossMonster* DrossMonster)
{
	ActiveMonsters.Remove(DrossMonster);
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::Deinitialize()
{
	Super::Deinitialize();
}

// -----------------------------------------------------------------------------

TStatId UDrossSiegeSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UDrossSiegeSusbystem, STATGROUP_Tickables);
}
