// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Enemies/Public/DrossMonster.h"

#include "BubblesFromTheDeep/Enemies/Public/DrossMonsterController.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void ADrossMonster::InitializeEnemy_Implementation(AGameBoardSlot* TargetSlotIn)
{
	SpawnDefaultController();
	DrossMonsterController = Cast<ADrossMonsterController>(GetController());
	DrossMonsterController->SetTargetSlot(TargetSlotIn);
	DrossMonsterController->Start();
}

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
	
}

// -----------------------------------------------------------------------------

// Called every frame
void ADrossMonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

