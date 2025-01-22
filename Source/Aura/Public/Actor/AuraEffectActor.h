// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameplayEffectTypes.h"
#include "AuraEffectActor.generated.h"


class UGameplayEffect;
class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy
{
	ApplyOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovelPolicy
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AAuraEffectActor();

protected:

	UFUNCTION(Blueprintable, BlueprintCallable)
	void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectToApplyClass);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	bool bDestroyOnEffectRemoval = false;

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
	
	// TSubClassOf means we are setting the class from BP, but using it in code.
	// Same concept we do with UI / Widgets
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	TSubclassOf<UGameplayEffect> InstantGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::ApplyOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	TSubclassOf<UGameplayEffect> DurationGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	EEffectApplicationPolicy DurationGameplayEffectPolicy = EEffectApplicationPolicy::ApplyOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffect;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	EEffectApplicationPolicy InfiniteGameplayEffectPolicy = EEffectApplicationPolicy::ApplyOverlap;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS | Applied Effects");
	EEffectRemovelPolicy InfiniteEffectRemovalPolicy = EEffectRemovelPolicy::RemoveOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;
	

	
	

};
