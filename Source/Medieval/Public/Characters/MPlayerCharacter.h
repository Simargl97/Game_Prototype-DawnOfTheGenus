// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/MCharacter.h"
#include "Characters/Interfaces/MPlayerInfo.h"
#include "MPlayerCharacter.generated.h"

class UInputAction;
class UMBowEquipmentComponent;
class UMCameraComponent;
class UMCameraShakeSourceComponent;
class UMInteractComponent;
class USceneComponent;
class UMStaminaComponent;
struct FInputActionValue;

UCLASS(Abstract)
class MEDIEVAL_API AMPlayerCharacter final : public AMCharacter, public IMPlayerInfo
{
	GENERATED_BODY()
	
public:
	explicit AMPlayerCharacter(const FObjectInitializer& ObjInit);
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent);
	virtual void AddControllerPitchInput(const float Value) override;
	virtual void AddControllerYawInput(const float Value) override;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UMCameraComponent* CameraComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMCameraShakeSourceComponent* CameraShakeSourceComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMInteractComponent* InteractComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMStaminaComponent* StaminaComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Components")
	USceneComponent* BowSceneComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USceneComponent* BowCombatSceneComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMBowEquipmentComponent* BowEquipmentComponent;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* MovementAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* LookingAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* JumpAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* SprintingAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* InteractAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* ToggleCombatModeAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* ChargeAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Input")
	UInputAction* FireAction;

	void OnEnteredInteractingActor(AActor* InteractingActor);
	void OnLeftInteractingActor(AActor* InteractingActor);
	void Move(const FInputActionValue& ActionValue);
	void Look(const FInputActionValue& ActionValue);
	void StartSprinting();
	void StopSprinting();
	void SetMovementType(const EMMovementType& MovementType);
	void Interact();
};