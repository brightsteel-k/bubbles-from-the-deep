// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DrossMonster.generated.h"

// -----------------------------------------------------------------------------
// Delegate Definitions
// -----------------------------------------------------------------------------

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDrossMonsterKilled);

// -----------------------------------------------------------------------------
// Forward Declarations
// -----------------------------------------------------------------------------

class AAICDrossMonster;

// -----------------------------------------------------------------------------
// Class Definition
// -----------------------------------------------------------------------------

UCLASS(Blueprintable, BlueprintType)
class BUBBLESFROMTHEDEEP_API ADrossMonster : public ACharacter
{
	GENERATED_BODY()

public:
	// -----------------------------------------------------------------------------
	// Public Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(EditAnywhere, BlueprintReadWrite, BlueprintAssignable, BlueprintAssignable)
	FOnDrossMonsterKilled OnKilled;

	UPROPERTY(BlueprintReadOnly)
	bool bIsAlive = true;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHealth = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Health;
	
	// -----------------------------------------------------------------------------
	// Public Methods
	// -----------------------------------------------------------------------------

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void EnterAdvancingMode();
	
	// Sets default values for this character's properties
	ADrossMonster();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void Die();
	void Die_Implementation();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void MonsterTakeDamage(float Damage);
	void MonsterTakeDamage_Implementation(float Damage);
	
protected:
	// -----------------------------------------------------------------------------
	// Protected Member Variables
	// -----------------------------------------------------------------------------

	UPROPERTY(BlueprintReadOnly)
	AAICDrossMonster* DrossMonsterController;

	
	// -----------------------------------------------------------------------------
	// Protected Methods
	// -----------------------------------------------------------------------------
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
};
