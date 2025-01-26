// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoralTurret.h"
#include "Components/ActorComponent.h"
#include "TurretAbilityComponent.generated.h"

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API UTurretAbilityComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	// Sets default values for this component's properties
	UTurretAbilityComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType,
	                           FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void SetOnCooldown(float OnCooldownForSeconds);
	
protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintReadOnly)
	ACoralTurret* CoralTurret;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float CooldownSeconds;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bOnCooldown;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LastUsedGameTime;
	
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------

	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
	bool CanTriggerAbility();
	virtual bool CanTriggerAbility_Implementation();

	UFUNCTION(BlueprintCallable,  BlueprintNativeEvent)
	void TriggerAbility();
};
