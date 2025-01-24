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
	for (const FGameplayTag& Tag : TagContainer)
	{
		// TODO: Broadcast the tag to the WidgetControllerClass
		const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
		GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Blue, FString(Msg));
	}
}
