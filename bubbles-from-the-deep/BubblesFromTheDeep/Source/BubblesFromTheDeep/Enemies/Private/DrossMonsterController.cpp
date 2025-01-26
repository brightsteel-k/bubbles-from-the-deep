// Fill out your copyright notice in the Description page of Project Settings.


#include "BubblesFromTheDeep/Enemies/Public/DrossMonsterController.h"
#include "BubblesFromTheDeep/Enemies/Public/DrossMonster.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void ADrossMonsterController::SetTargetSlot(AGameBoardSlot* TargetSlotIn)
{
	TargetSlot = TargetSlotIn;
}

// -----------------------------------------------------------------------------

AGameBoardSlot* ADrossMonsterController::GetTargetSlot()
{
	return TargetSlot;
}

// -----------------------------------------------------------------------------

void ADrossMonsterController::Start_Implementation()
{
	DrossMonster = Cast<ADrossMonster>(GetPawn());
	BehaviorPhase = Rising;
}

// -----------------------------------------------------------------------------

// Sets default values
ADrossMonsterController::ADrossMonsterController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// -----------------------------------------------------------------------------

// Called when the game starts or when spawned
void ADrossMonsterController::BeginPlay()
{
	Super::BeginPlay();
	
}

// -----------------------------------------------------------------------------

// Called every frame
void ADrossMonsterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

