// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameBoardSlot.h"
#include "GameFramework/Character.h"
#include "DrossMonster.generated.h"

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API ADrossMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void InitializeEnemy(AGameBoardSlot* TargetSlotIn);
	void InitializeEnemy_Implementation(AGameBoardSlot* TargetSlotIn);
	
	// Sets default values for this character's properties
	ADrossMonster();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintReadWrite)
	AGameBoardSlot* TargetSlot;
	
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
