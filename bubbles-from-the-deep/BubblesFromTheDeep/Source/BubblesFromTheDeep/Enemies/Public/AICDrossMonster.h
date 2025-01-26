// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GameBoardSlot.h"
#include "GameFramework/Controller.h"
#include "AICDrossMonster.generated.h"

// -----------------------------------------------------------------------------
// Forward Declarations
// -----------------------------------------------------------------------------

class ADrossMonster;

// -----------------------------------------------------------------------------
// Enum Definition
// -----------------------------------------------------------------------------

UENUM(Blueprintable, BlueprintType)
enum EMonsterBehaviorPhase
{
	Rising = 0,
	Advancing = 1,
	Attacking = 2,
	Stunned = 3
};

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API AAICDrossMonster : public AAIController
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------
	
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable)
	void SetTargetSlot(AGameBoardSlot* TargetSlotIn);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	AGameBoardSlot* GetTargetSlot();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Start();
	virtual void Start_Implementation();
	
	// Sets default values for this actor's properties
	AAICDrossMonster();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintReadWrite)
	TEnumAsByte<EMonsterBehaviorPhase> BehaviorPhase;
	
	UPROPERTY(BlueprintReadWrite)
	AGameBoardSlot* DestinationSlot;

	UPROPERTY(BlueprintReadWrite)
	ACoralTurret* CurrentTarget;

	UPROPERTY(BlueprintReadOnly)
	ADrossMonster* DrossMonster;
	
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentTarget(ACoralTurret* Turret);
	
	UFUNCTION(BlueprintNativeEvent)
	void OnCurrentTargetDies();
	void OnCurrentTargetDies_Implementation();
};
