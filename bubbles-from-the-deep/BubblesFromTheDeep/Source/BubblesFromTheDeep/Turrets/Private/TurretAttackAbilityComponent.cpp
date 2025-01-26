// Fill out your copyright notice in the Description page of Project Settings.

#include "BubblesFromTheDeep/Turrets/Public/TurretAttackAbilityComponent.h"

// -----------------------------------------------------------------------------
// Class Implementation
// -----------------------------------------------------------------------------

// Sets default values for this component's properties
UTurretAttackAbilityComponent::UTurretAttackAbilityComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// -----------------------------------------------------------------------------

// Called when the game starts
void UTurretAttackAbilityComponent::BeginPlay()
{
	Super::BeginPlay();
	DrossSiegeSubsystem = GetWorld()->GetSubsystem<UDrossSiegeSubsystem>();
}

// -----------------------------------------------------------------------------

bool UTurretAttackAbilityComponent::CanTriggerAbility_Implementation()
{
	// Current target is still valid
	if (CurrentTarget && FVector::DistSquaredXY(CoralTurret->GetActorLocation(), CurrentTarget->GetActorLocation())
		<= AttackRange * AttackRange) {
		return true;
	}

	// Find new target in closest monster
	ADrossMonster* ClosestTarget;
	if (DrossSiegeSubsystem->IsMonsterWithinRange(CoralTurret->GetActorLocation(), AttackRange, ClosestTarget)) {
		SetCurrentTarget(ClosestTarget);
		return true;
	}
	
	return false;
}

// -----------------------------------------------------------------------------

void UTurretAttackAbilityComponent::SetCurrentTarget(ADrossMonster* DrossMonster)
{
	CurrentTarget = DrossMonster;
	CurrentTarget->OnKilled.AddDynamic(this, &UTurretAttackAbilityComponent::OnCurrentTargetDies);
}

// -----------------------------------------------------------------------------

void UTurretAttackAbilityComponent::OnCurrentTargetDies()
{
	CurrentTarget = nullptr;
}

// -----------------------------------------------------------------------------

// Called every frame
void UTurretAttackAbilityComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                                  FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

