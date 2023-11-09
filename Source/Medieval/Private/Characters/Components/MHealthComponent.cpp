// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/MHealthComponent.h"

void UMHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	SetCurrentHealth(MaxHealth);
}

void UMHealthComponent::SetCurrentHealth(const float InCurrentHealth)
{
	if (!bIsDead)
	{
		CurrentHealth = FMath::Clamp(InCurrentHealth, 0, MaxHealth);
		if (FMath::IsNearlyZero(CurrentHealth))
		{
			bIsDead = true;
			OnDead.Broadcast();
		}
	}
}

bool UMHealthComponent::IsDead()
{
	return bIsDead;
}

void UMHealthComponent::AddHealth(const float Add)
{
	SetCurrentHealth(CurrentHealth + Add);
}

void UMHealthComponent::ReduceHealth(const float Reduce)
{
	SetCurrentHealth(CurrentHealth - Reduce);
}