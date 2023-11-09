// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MStaminaComponent.h"
#include "Characters/Interfaces/MMovement.h"
#include "MCharacterMovementComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMCharacterMovementComponent final: public UCharacterMovementComponent , public IMMovement
{
	GENERATED_BODY()

public:
	void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction);
	virtual float GetMaxSpeed() const override;
	virtual bool DoJump(bool bReplayingMoves) override;
	virtual bool IsInAir() const override;
	virtual void SetStamina(IMStamina* InStamina) override;
	virtual void SetMovementType(const EMMovementType& InMovementType) override;
	virtual void SetCanMove() override;
	virtual void ResetCanMove() override;
	virtual bool CanMove() const override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TMap<EMMovementType, float> Speeds{ {EMMovementType::Sprinting, 900.0f}, {EMMovementType::Running, 600.0f}, {EMMovementType::Walking, 200.0f},};

	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TMap<EMMovementType, float> StaminaUsagesPerSecond{ {EMMovementType::Sprinting, 15.0f}, {EMMovementType::Running, 0.0f}, {EMMovementType::Walking, 0.0f}, };

	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	float StaminaUsagePerJump = 10.0f;

	IMStamina* Stamina;
	EMMovementType MovementType = EMMovementType::Running;
	bool bCanMove = true;
	
	void RanOutStamina();
};
