// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TurretAbilityComponent.h"
#include "BubblesFromTheDeep/Enemies/Public/DrossSiegeSubsystem.h"
#include "TurretAttackAbilityComponent.generated.h"

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API UTurretAttackAbilityComponent : public UTurretAbilityComponent
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	// Sets default values for this component's properties
	UTurretAttackAbilityComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackRange;

	UPROPERTY(BlueprintReadWrite)
	ADrossMonster* CurrentTarget;

	UPROPERTY()
	UDrossSiegeSubsystem* DrossSiegeSubsystem;
	
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------

	// Called when the game starts
	virtual void BeginPlay() override;

	virtual bool CanTriggerAbility_Implementation() override;
	
	UFUNCTION(BlueprintCallable)
	void SetCurrentTarget(ADrossMonster* DrossMonster);
	
	UFUNCTION()
	void OnCurrentTargetDies();
};
