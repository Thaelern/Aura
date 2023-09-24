// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();

	
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem)
	Subsystem->AddMappingContext(AuraContext, 0);


	/* Generic mouse settings. No point in memorizing any of this. Just set and re-call next time you need this type of game */
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}
void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent); // Casting from InputComponent to Enhanced. CastChecked will crash the compiler if not possible.

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move); // Binding the MoveAction. This is a public var. Setting it from the BP in editor
}
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputAxisVector = InputActionValue.Get<FVector2d>(); // Gets both XY axis values 
	const FRotator Rotation = GetControlRotation(); // UNSURE - Gets the rotation of the controller is facing ?
	const FRotator YawRotation(0.f, Rotation.Yaw,  0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection,InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisVector.X);
	}
	
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECollisionChannel::ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/*
	 * Line trace from cursor. There are several scenarios:
	 * A: LastActor is null && ThisActor is null
	 *			-Do nothing
	 *
	 *	B: Last Actor is null %% ThisActor is Valid
	 *			- Highlight ThisActor
	 *
	 *	C: Last Actor is valid && ThisActor is null
	 *			- LastActor UnHighLight
	 *
	 *	D: Both Actors are valid, But lastActor != ThisActor
	 *			- LastActor UnHighLight, ThisActor HighLight
	 *
	 *	E: Both Actors are valid and are the same actor
	 *			- Do nothing
	 */

	if(LastActor == nullptr)
	{
		if(ThisActor != nullptr)
		{
			// Case B.
			ThisActor->HightLightActor();
		}
		else
		{
			// Case A.  both are null, do nothing.
		}
	}
	else // LastActor is valid
	{
		if(ThisActor == nullptr)
		{
			// Case C.
			LastActor->UnHighLightActor();
		}
		else // both actors are valid
		{
			if(LastActor != ThisActor)
			{
				// Case D.
				LastActor->UnHighLightActor();
				ThisActor->UnHighLightActor();
			}
			else
			{
				// Case E.
				// Do Nothing
			}
		}
	}
	
}
