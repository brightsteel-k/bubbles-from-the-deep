// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Enemies/Public/DrossMonster.h"

#include "GameBoard.h"
#include "BubblesFromTheDeep/Enemies/Public/AICDrossMonster.h"
#include "BubblesFromTheDeep/Enemies/Public/DrossSiegeSubsystem.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

// Sets default values
ADrossMonster::ADrossMonster()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// -----------------------------------------------------------------------------

// Called when the game starts or when spawned
void ADrossMonster::BeginPlay()
{
	Super::BeginPlay();
	DrossMonsterController = Cast<AAICDrossMonster>(GetController());
	GetWorld()->GetSubsystem<UDrossSiegeSubsystem>()->OnDrossMonsterSpawned(this);
	Health = MaxHealth;
}

// -----------------------------------------------------------------------------

// Called every frame
void ADrossMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

void ADrossMonster::Die_Implementation()
{
	if (!bIsAlive) {
		return;
	}
	
	bIsAlive = false;
	GetWorld()->GetSubsystem<UDrossSiegeSubsystem>()->OnDrossMonsterKilled(this);
	OnKilled.Broadcast();
}

// -----------------------------------------------------------------------------

void ADrossMonster::MonsterTakeDamage_Implementation(float Damage)
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
