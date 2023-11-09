// Copyright (c). Medieval . Author: Sergoe Osipchuk

#include "Characters/MPlayerCharacter.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/Components/Camera/MCameraComponent.h"
#include "Characters/Components/Camera/MCameraShakeSourceComponent.h"
#include "Characters/Components/Equipments/MBowEquipmentComponent.h"
#include "Characters/Components/MStaminaComponent.h"
#include "Characters/Components/MInteractComponent.h"
#include "Core/Interfaces/MInteract.h"

AMPlayerCharacter::AMPlayerCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit)
{
	StaminaComponent = CreateDefaultSubobject<UMStaminaComponent>(TEXT("StaminaComponent"));
	IMMovement* Movement = Cast<IMMovement>(GetCharacterMovement());
	check(Movement);
	Movement->SetStamina(StaminaComponent);

	CameraComponent = CreateDefaultSubobject<UMCameraComponent>(TEXT("CameraComponent"));
	check(CameraComponent);
	CameraComponent->bUsePawnControlRotation = true;
	CameraComponent->SetStamina(StaminaComponent);
	CameraComponent->SetupAttachment(GetMesh());

	CameraShakeSourceComponent = CreateDefaultSubobject<UMCameraShakeSourceComponent>(TEXT("CameraShakeSourceComponent"));
	check(CameraShakeSourceComponent);
	CameraShakeSourceComponent->SetStamina(StaminaComponent);
	CameraShakeSourceComponent->SetupAttachment(GetRootComponent());

	InteractComponent = CreateDefaultSubobject<UMInteractComponent>(TEXT("InteractComponent"));
	check(InteractComponent);
	InteractComponent->OnEntered.AddUObject(this, &ThisClass::OnEnteredInteractingActor);
	InteractComponent->OnLeft.AddUObject(this, &ThisClass::OnLeftInteractingActor);

	BowSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BowSceneComponent"));
	check(BowSceneComponent);
	BowSceneComponent->SetupAttachment(GetMesh());

	BowCombatSceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("BowCombatSceneComponent"));
	check(BowCombatSceneComponent);
	BowCombatSceneComponent->SetupAttachment(CameraComponent);

	BowEquipmentComponent = CreateDefaultSubobject<UMBowEquipmentComponent>(TEXT("BowEquipmentComponent"));
	check(BowEquipmentComponent);
	BowEquipmentComponent->SetStamina(StaminaComponent);
	BowEquipmentComponent->SetCameraShakeSource(CameraShakeSourceComponent);
	BowEquipmentComponent->SetEquippedSceneComponent(BowSceneComponent);
	BowEquipmentComponent->SetCombatEquippedSceneComponent(BowCombatSceneComponent);
}

void AMPlayerCharacter::OnEnteredInteractingActor(AActor* InteractingActor)
{
		IMInteract* Interact = Cast<IMInteract>(InteractingActor);
		if (Interact)
		{
			Interact->OnEnter();
		}
}

void AMPlayerCharacter::OnLeftInteractingActor(AActor* InteractingActor)
{
	IMInteract* Interact = Cast<IMInteract>(InteractingActor);
	if (Interact)
	{
		Interact->OnLeave();
	}
}

void AMPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	check(InteractComponent);
	InteractComponent->Start(CameraComponent);
}

void AMPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	check(EnhancedInputComponent);
	check(MovementAction);
	check(LookingAction);
	check(JumpAction);
	check(SprintingAction);
	check(InteractAction);
	check(ToggleCombatModeAction);
	check(ChargeAction);
	check(FireAction);

	EnhancedInputComponent->BindAction(MovementAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
	EnhancedInputComponent->BindAction(LookingAction, ETriggerEvent::Triggered, this, &ThisClass::Look);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ThisClass::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ThisClass::StopJumping);
	EnhancedInputComponent->BindAction(SprintingAction, ETriggerEvent::Started, this, &ThisClass::StartSprinting);
	EnhancedInputComponent->BindAction(SprintingAction, ETriggerEvent::Completed, this, &ThisClass::StopSprinting);
	EnhancedInputComponent->BindAction(InteractAction, ETriggerEvent::Started, this, &ThisClass::Interact);
	EnhancedInputComponent->BindAction(ToggleCombatModeAction, ETriggerEvent::Started, BowEquipmentComponent, &UMBowEquipmentComponent::ToggleCombatMode);
	EnhancedInputComponent->BindAction(ChargeAction, ETriggerEvent::Started, BowEquipmentComponent, &UMBowEquipmentComponent::StartCharge);
	EnhancedInputComponent->BindAction(ChargeAction, ETriggerEvent::Completed, BowEquipmentComponent, &UMBowEquipmentComponent::StopCharge);
	EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Started, BowEquipmentComponent, &UMBowEquipmentComponent::Fire);
}

void AMPlayerCharacter::Move(const FInputActionValue& ActionValue)
{
	if (!FMath::IsNearlyZero(ActionValue.GetMagnitude()) && CanMove())
	{
		AddMovementInput(GetActorForwardVector(), ActionValue[1]);
		AddMovementInput(GetActorRightVector(), ActionValue[0]);
	}
}

void AMPlayerCharacter::Look(const FInputActionValue& ActionValue)
{
	if (!FMath::IsNearlyZero(ActionValue.GetMagnitude()) && CanMove())
	{
		AddControllerPitchInput(ActionValue[1]);
		AddControllerYawInput(ActionValue[0]);
	}
}

void AMPlayerCharacter::AddControllerPitchInput(const float Value)
{
	if (CanMove())
	{
		Super::AddControllerPitchInput(Value);
	}
}

void AMPlayerCharacter::AddControllerYawInput(const float Value)
{
	if (CanMove())
	{
		Super::AddControllerYawInput(Value);
	}
}

void AMPlayerCharacter::StartSprinting()
{
	SetMovementType(EMMovementType::Sprinting);
}

void AMPlayerCharacter::SetMovementType(const EMMovementType& MovementType)
{
	IMMovement* Movement = Cast<IMMovement>(GetCharacterMovement());
	check(Movement);
	Movement->SetMovementType(MovementType);
}

void AMPlayerCharacter::StopSprinting()
{
	SetMovementType(EMMovementType::Running);
}

void AMPlayerCharacter::Interact()
{
	check(InteractComponent);
	IMInteract* Interact = Cast<IMInteract>(InteractComponent->GetInteractingActor());
	if (Interact)
	{
		Interact->Interact(this);
	}
}