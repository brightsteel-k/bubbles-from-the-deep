// Fill out your copyright notice in the Description page of Project Settings.

#include "CoralTurret.h"
#include "GameBoardSlot.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void ACoralTurret::OnTurretPlaced_Implementation(AGameBoardSlot* Slot)
{
	OwningGameBoardSlot = Slot;
}

// -----------------------------------------------------------------------------

AGameBoardSlot* ACoralTurret::GetOwningGameBoardSlot()
{
	return OwningGameBoardSlot;
}

// -----------------------------------------------------------------------------

void ACoralTurret::Die_Implementation()
{
	if (!bIsAlive) {
		return;
	}

	bIsAlive = false;
	OnTurretDestroyed.Broadcast();
	OwningGameBoardSlot->OnTurretCleared();
}

// -----------------------------------------------------------------------------

void ACoralTurret::TurretTakeDamage_Implementation(float Damage)
{
	if (Damage <= 0) {
		return;
	}
	
	if (Health <= Damage) {
		Health = 0;
		Die();
	} else {
		Health -= Damage;
	}
}

// -----------------------------------------------------------------------------

// Sets default values
ACoralTurret::ACoralTurret()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// -----------------------------------------------------------------------------

// Called when the game starts or when spawned
void ACoralTurret::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
}

// -----------------------------------------------------------------------------

// Called every frame
void ACoralTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

