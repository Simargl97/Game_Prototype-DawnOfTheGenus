// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/Camera/MCameraShakeSourceComponent.h"
#include "Characters/Interfaces/MStamina.h"


void UMCameraShakeSourceComponent::StartShaking()
{
	check(Stamina);
	Stamina->OnChangedStamina().AddUObject(this, &ThisClass::StaminaEffects);
	StaminaEffects();
}

void UMCameraShakeSourceComponent::StaminaEffects()
{
	const float Scale = GetScale();
	if (FMath::Abs(LastScale - Scale) > Treshhold)
	{
		StartCameraShake(CameraShake, Scale);
		LastScale = Scale;
	}
}

float UMCameraShakeSourceComponent::GetScale() const
{
	check(Stamina);
	return 1 - Stamina->GetPercentStamina();
}

void UMCameraShakeSourceComponent::StopShaking()
{
	check(Stamina);
	Stamina->OnChangedStamina().RemoveAll(this);
	StopAllCameraShakes();
	LastScale = 0.0f;
}

void UMCameraShakeSourceComponent::SetStamina(IMStamina* InStamina)
{
	Stamina = InStamina;
}
