// Fill out your copyright notice in the Description page of Project Settings.

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

#include "BubblesFromTheDeep/Enemies/Public/DrossSiege.h"
void UDrossSiege::GetDrossSiegeWaves(TArray<FDrossMonsterWave>& DrossSiegeWavesOut)
{
	DrossSiegeWavesOut.Empty(Waves.Num());
	for (FDrossMonsterWave Wave : Waves) {
		DrossSiegeWavesOut.Add(Wave);
	}
}
