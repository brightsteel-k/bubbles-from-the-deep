// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoardSlot.h"
#include "CoralTurret.h"
#include "GameBoard.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

void AGameBoardSlot::PlaceTurret(TSubclassOf<ACoralTurret> TurretClass)
{
	// Prepare for placement
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.Owner = this;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	FTransform SpawnTransform = GetActorTransform();

	// Spawn turret actor
	AActor* NewTurret = GetWorld()->SpawnActor(TurretClass, &SpawnTransform, SpawnParameters);
	ensure(NewTurret != nullptr);

	// Socket turret
	SocketedTurret = Cast<ACoralTurret>(NewTurret);
	SocketedTurret->OnTurretPlaced(this);
	OnTurretPlaced();
}

// -----------------------------------------------------------------------------

ACoralTurret* AGameBoardSlot::GetTurret()
{
	return SocketedTurret;
}

// -----------------------------------------------------------------------------

bool AGameBoardSlot::HasTurret()
{
	return SocketedTurret != nullptr;
}

// -----------------------------------------------------------------------------

void AGameBoardSlot::OnTurretCleared_Implementation()
{
	SocketedTurret = nullptr;
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

