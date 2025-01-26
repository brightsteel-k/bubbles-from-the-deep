// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BubblesFromTheDeep/Enemies/Public/DrossSiege.h"
#include "GameFramework/Actor.h"
#include "GameBoard.generated.h"

// -----------------------------------------------------------------------------
// Forward Declarations
// -----------------------------------------------------------------------------

class AGameBoardSlot;

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------
UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API AGameBoard : public AActor
{
	GENERATED_BODY()
	
public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	static AGameBoard* CurrentGameBoard;
	
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
	TArray<AGameBoardSlot*> GameBoardSlots;

	UPROPERTY(BlueprintReadWrite)
	AGameBoardSlot* TargetSlot;
	
	// Sets default values for this actor's properties
	AGameBoard();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AGameBoardSlot* GetTargetSlot();

	UFUNCTION(BlueprintCallable)
	void SetTargetSlot(AGameBoardSlot* Slot);

	UFUNCTION(BlueprintCallable)
	ADrossMonster* SpawnDrossMonster(TSubclassOf<ADrossMonster> MonsterClass, float SpawnpointAngle);

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void SpawnDrossMonsterWave(TSubclassOf<ADrossMonster> MonsterClass, int WaveSize,
		FFloatInterval SpawnpointAngleRange);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static AGameBoard* GetGameBoard();

	UFUNCTION(BlueprintCallable)
	static void SetCurrentGameBoard(AGameBoard* GameBoard);

	UFUNCTION(BlueprintCallable)
	static void ClearCurrentGameBoard();

protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDrossSiege* DrossSiege;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFloatInterval DrossMonsterSpawnRelativeHeight = FFloatInterval(10, 30);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float DrossMonsterSpawnRadius = 250;
	
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void RegisterGameBoardSlots();

	UFUNCTION(BlueprintCallable)
	void RegisterGameBoardSlot(AGameBoardSlot* Slot);
};
