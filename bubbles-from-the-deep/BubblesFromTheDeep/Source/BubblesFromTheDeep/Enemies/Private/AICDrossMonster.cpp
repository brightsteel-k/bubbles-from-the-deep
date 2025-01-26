// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblesFromTheDeep/Enemies/Public/AICDrossMonster.h"

#include "GameBoard.h"
#include "BubblesFromTheDeep/Enemies/Public/DrossMonster.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void AAICDrossMonster::SetTargetSlot(AGameBoardSlot* TargetSlotIn)
{
	DestinationSlot = TargetSlotIn;
}

// -----------------------------------------------------------------------------

AGameBoardSlot* AAICDrossMonster::GetTargetSlot()
{
	return DestinationSlot;
}

// -----------------------------------------------------------------------------

void AAICDrossMonster::Start_Implementation()
{
	DrossMonster = Cast<ADrossMonster>(GetPawn());
	BehaviorPhase = Rising;
}

// -----------------------------------------------------------------------------

// Sets default values
AAICDrossMonster::AAICDrossMonster()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// -----------------------------------------------------------------------------

// Called when the game starts or when spawned
void AAICDrossMonster::BeginPlay()
{
	Super::BeginPlay();
	SetTargetSlot(AGameBoard::GetGameBoard()->GetTargetSlot());
	Start();
}

// -----------------------------------------------------------------------------

// Called every frame
void AAICDrossMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

void AAICDrossMonster::SetCurrentTarget(ACoralTurret* Turret)
{
	CurrentTarget = Turret;
	CurrentTarget->OnTurretDestroyed.AddDynamic(this, &AAICDrossMonster::OnCurrentTargetDies);
}

// -----------------------------------------------------------------------------

void AAICDrossMonster::OnCurrentTargetDies_Implementation()
{
	CurrentTarget = nullptr;
}

// -----------------------------------------------------------------------------
