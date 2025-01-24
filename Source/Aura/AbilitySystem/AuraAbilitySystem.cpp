// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraAbilitySystem.h"

void UAuraAbilitySystem::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystem::EffectApplied);
}

void UAuraAbilitySystem::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
                                       const FGameplayEffectSpec& EffectSpec,
                                       FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	EffectAssetTags.Broadcast(TagContainer);
	

}
