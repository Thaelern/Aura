// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "AuraCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * 
 */
UCLASS()
class AURA_API AAuraCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()

public:
	AAuraCharacter(); // Constructor


	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

protected:

private:
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArm;


	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> MainPlayerCamera;

	UPROPERTY(EditAnywhere, Category = "Movement")
	FRotator DefaultRotationRate = FRotator(0.f, 400.f, 0.f);

	void InitAbilityActorInfo();
	
	
};
