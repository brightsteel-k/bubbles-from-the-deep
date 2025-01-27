// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Enemies/Public/DrossSiegeSubsystem.h"

#include "GameBoard.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::StartSiege()
{
	bIsSiegeActive = true;
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::StartNextSiegeWave()
{
	if (!SiegeWaves.IsValidIndex(CurrentSiegeIndex)) {
		return;
	}
	
	FDrossMonsterWave CurrentWave = SiegeWaves[CurrentSiegeIndex];

	// Process current wave
	TSubclassOf<ADrossMonster> MonsterClass = CurrentWave.DrossMonsterClass;
	int WaveSize = UKismetMathLibrary::RandomIntegerInRange(CurrentWave.WaveSize.Min, CurrentWave.WaveSize.Max);
	FFloatInterval SpawnpointAngleRange = CurrentWave.SpawnpointAngleRange;
	AGameBoard::GetGameBoard()->SpawnDrossMonsterWave(MonsterClass, WaveSize, SpawnpointAngleRange);

	// Queue next wave
	if (SiegeWaves.Num() > ++CurrentSiegeIndex) {
		NextWaveTime = UGameplayStatics::GetTimeSeconds(this) + CurrentWave.WaveDurationSeconds;
	} else {
		bIsSiegeEnding = true;
	}
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

	if (bIsSiegeEnding && ActiveMonsters.IsEmpty()) {
		WinDrossSiege();
	}
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::WinDrossSiege()
{
	UGameplayStatics::OpenLevel(this, TEXT("LVL_WinScreen"), TRAVEL_Absolute);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Emerald, FString(TEXT("SIEGE WON!")));
}

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::LoseDrossSiege()
{
	UGameplayStatics::OpenLevel(this, TEXT("LVL_GameOver"), TRAVEL_Absolute);
	GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString(TEXT("SIEGE LOST")));

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

	if (bIsSiegeActive && !bIsSiegeEnding) {
		if (UGameplayStatics::GetTimeSeconds(this) >= NextWaveTime) {
			StartNextSiegeWave();
		}
	}
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

// -----------------------------------------------------------------------------

void UDrossSiegeSubsystem::LoadSiege(UDrossSiege* DrossSiegeIn)
{
	if (bIsSiegeActive) {
		return;
	}
	DrossSiegeIn->GetDrossSiegeWaves(SiegeWaves);
}
