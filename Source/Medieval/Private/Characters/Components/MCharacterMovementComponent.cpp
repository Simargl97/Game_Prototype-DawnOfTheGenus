// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/MCharacterMovementComponent.h"
#include "Characters/Interfaces/MStamina.h"

void UMCharacterMovementComponent::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)

{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!Stamina) return;
	check(Speeds.Contains(MovementType));
	check(GetOwner());
	const float OwnerVelocity = GetOwner()->GetVelocity().Length();
	if (!FMath::IsNearlyZero(OwnerVelocity))
	{
		Stamina->UseStamina(StaminaUsagesPerSecond[MovementType] * DeltaTime);
	}
}

float UMCharacterMovementComponent::GetMaxSpeed() const
{
	check(Speeds.Contains(MovementType));
	return Speeds[MovementType];
}

bool UMCharacterMovementComponent::DoJump(bool bReplayingMoves)
{
	if (!bCanMove) return false;

	if (!Stamina)
	{
		return Super::DoJump(bReplayingMoves);
	}

	if (Stamina->GetCurrentStamina() > StaminaUsagePerJump)
	{
		Stamina->UseStamina(StaminaUsagePerJump);
		return Super::DoJump(bReplayingMoves);
	}
		return false;
}

bool UMCharacterMovementComponent::IsInAir() const
{
	return IsFalling();
}

void UMCharacterMovementComponent::SetStamina(IMStamina* InStamina)
{
	Stamina = InStamina;
	check(Stamina);
	Stamina->OnRanOutStamina().AddUObject(this, &ThisClass::RanOutStamina);
}

void UMCharacterMovementComponent::RanOutStamina()
{
	for (const TPair<EMMovementType, float>& Pair : StaminaUsagesPerSecond)
	{
		if (FMath::IsNearlyZero(Pair.Value))
		{
			SetMovementType(Pair.Key);
			return;
		}
	}
	StopMovementImmediately();
}

void UMCharacterMovementComponent::SetMovementType(const EMMovementType& InMovementType)
{
	MovementType = InMovementType;
}

void UMCharacterMovementComponent::SetCanMove()
{
	bCanMove = true;
}

void UMCharacterMovementComponent::ResetCanMove()
{
	bCanMove = false;
}

bool UMCharacterMovementComponent::CanMove() const
{
	return bCanMove;
}
