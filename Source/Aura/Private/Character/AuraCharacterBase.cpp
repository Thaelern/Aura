 // Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon"); // string doens't need TEXT() macro, because it is an FNAME and not a FString
	Weapon->SetupAttachment(GetMesh(), FName("WeaponHandSocket")); // The FName - Set in the skeletal mesh in editor. :)
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

 UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
 {
	return AbilitySystemComponent;
 }


 void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

 void AAuraCharacterBase::InitAbilityActorInfo()
 {
 }



