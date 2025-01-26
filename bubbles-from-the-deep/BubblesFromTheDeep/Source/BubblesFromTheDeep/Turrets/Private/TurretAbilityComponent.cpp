// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Turrets/Public/TurretAbilityComponent.h"

#include "Kismet/GameplayStatics.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

// Sets default values for this component's properties
UTurretAbilityComponent::UTurretAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

// -----------------------------------------------------------------------------

// Called when the game starts
void UTurretAbilityComponent::BeginPlay()
{
	CoralTurret = Cast<ACoralTurret>(GetOwner());
	Super::BeginPlay();
}

// -----------------------------------------------------------------------------

bool UTurretAbilityComponent::CanTriggerAbility_Implementation()
{
	return true;
}

// -----------------------------------------------------------------------------

void UTurretAbilityComponent::TriggerAbility_Implementation()
{
	SetOnCooldown(CooldownSeconds);
}

// -----------------------------------------------------------------------------

// Called every frame
void UTurretAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                          FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (bOnCooldown) {
		if (LastUsedGameTime + CooldownSeconds < UGameplayStatics::GetTimeSeconds(this)) {
			bOnCooldown = false;
		}
	} else {
		if (CanTriggerAbility() && CoralTurret->bIsAlive) {
			TriggerAbility();
		}
	}
}

// -----------------------------------------------------------------------------

void UTurretAbilityComponent::SetOnCooldown(float OnCooldownForSeconds)
{
	if (OnCooldownForSeconds > 0) {
		bOnCooldown = true;
		CooldownSeconds = OnCooldownForSeconds;
		LastUsedGameTime = UGameplayStatics::GetTimeSeconds(this);
	}
}

