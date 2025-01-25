// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoardSlot.h"
#include "CoralTurret.h"
#include "GameBoard.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void AGameBoardSlot::SetSocketedTurret(ACoralTurret* NewTurret)
{
	SocketedTurret = NewTurret;
	NewTurret->OnTurretPlaced(this);
}

// -----------------------------------------------------------------------------

ACoralTurret* AGameBoardSlot::GetSocketedTurret()
{
	return SocketedTurret;
}

// -----------------------------------------------------------------------------

bool AGameBoardSlot::HasSocketedTurret()
{
	return SocketedTurret != nullptr;
}

// -----------------------------------------------------------------------------

void AGameBoardSlot::Initialize_Implementation(AGameBoard* ParentBoard)
{
	ParentGameBoard = ParentBoard;
}

// -----------------------------------------------------------------------------

// Sets default values
AGameBoardSlot::AGameBoardSlot()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// -----------------------------------------------------------------------------

// Called when the game starts or when spawned
void AGameBoardSlot::BeginPlay()
{
	Super::BeginPlay();
	
}

// -----------------------------------------------------------------------------

// Called every frame
void AGameBoardSlot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

