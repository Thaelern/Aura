// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"


class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:

	UFUNCTION(Blueprintable, BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectToApplyClass);
	
	// TSubClassOf means we are setting the class from BP, but using it in code.
	// Same concept we do with UI / Widgets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	TSubclassOf<UGameplayEffect> InstantGameplayEffect;

	
	

};
