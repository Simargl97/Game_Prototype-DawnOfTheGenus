// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/MExperienceComponent.h"

void UMExperienceComponent::BeginPlay()
{
	Super::BeginPlay();
	SetCurrentExp(MaxExp);
}

void UMExperienceComponent::SetCurrentExp(const float InCurrentExp)
{
	if (!bIsLevelUp)
	{
		CurrentExp = FMath::Clamp(InCurrentExp, 0, MaxExp);
		if (CurrentExp == MaxExp)
		{
			bIsLevelUp = true;
			LevelUp.Broadcast();
		}
	}
}

float UMExperienceComponent::GetCurrentLevel() const
{
	return CurrentLevel;
}

void UMExperienceComponent::AddExp(const float Add)
{
	SetCurrentExp(CurrentExp + Add);
}

void UMExperienceComponent::LevelUpPlayer(const float Level)
{
	CurrentLevel = CurrentLevel + 1;
	MaxExp = Level * MaxExp;
}
