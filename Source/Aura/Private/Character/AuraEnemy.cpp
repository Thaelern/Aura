// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemy.h"

#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	if(Weapon)
	{
		Weapon->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	}
	
}

void AAuraEnemy::HightLightActor()
{
	bShouldHighLight = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	if(Weapon)
	{
		Weapon->SetRenderCustomDepth(true);
	}
	
}

void AAuraEnemy::UnHighLightActor()
{
	bShouldHighLight = false;
	GetMesh()->SetRenderCustomDepth(false);
	if(Weapon)
	{
		Weapon->SetRenderCustomDepth(false);
	}
}
