// Fill out your copyright notice in the Description page of Project Settings.

#include "GameBoard.h"
#include "GameBoardSlot.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

AGameBoard* AGameBoard::CurrentGameBoard = nullptr;

// -----------------------------------------------------------------------------

// Sets default values
AGameBoard::AGameBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// -----------------------------------------------------------------------------

// Called when the game starts or when spawned
void AGameBoard::BeginPlay()
{
	Super::BeginPlay();
}

// -----------------------------------------------------------------------------

void AGameBoard::RegisterGameBoardSlot(AGameBoardSlot* Slot)
{
	GameBoardSlots.Add(Slot);
	Slot->Initialize(this);
}

// -----------------------------------------------------------------------------

// Called every frame
void AGameBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// -----------------------------------------------------------------------------

AGameBoardSlot* AGameBoard::GetTargetSlot()
{
	return TargetSlot;
}

// -----------------------------------------------------------------------------

void AGameBoard::SetTargetSlot(AGameBoardSlot* Slot)
{
	TargetSlot = Slot;
}

// -----------------------------------------------------------------------------

ADrossMonster* AGameBoard::SpawnDrossMonster(TSubclassOf<ADrossMonster> MonsterClass, float SpawnpointAngle)
{
	// Prepare spawn parameters
	FActorSpawnParameters SpawnParameters;
	SpawnParameters.bDeferConstruction = true;
	SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	// Calculate Location
	float RelativeHeight = UKismetMathLibrary::RandomFloatInRange(DrossMonsterSpawnRelativeHeight.Min,
		DrossMonsterSpawnRelativeHeight.Max);
	FVector SpawnOffset = FVector(DrossMonsterSpawnRadius, 0, RelativeHeight);
	FTransform SpawnTransform = FTransform(GetActorLocation()
		+ SpawnOffset.RotateAngleAxis(SpawnpointAngle, FVector(0, 0, 1)));

	// Spawn turret actor
	AActor* NewMonster = GetWorld()->SpawnActor(MonsterClass, &SpawnTransform, SpawnParameters);
	ensure(NewMonster != nullptr);
	UGameplayStatics::FinishSpawningActor(NewMonster, SpawnTransform);

	return Cast<ADrossMonster>(NewMonster);
}

// -----------------------------------------------------------------------------

AGameBoard* AGameBoard::GetGameBoard()
{
	return CurrentGameBoard;
}

// -----------------------------------------------------------------------------

void AGameBoard::SetCurrentGameBoard(AGameBoard* GameBoard)
{
	CurrentGameBoard = GameBoard;
}

// -----------------------------------------------------------------------------

void AGameBoard::ClearCurrentGameBoard()
{
	CurrentGameBoard = nullptr;
}
