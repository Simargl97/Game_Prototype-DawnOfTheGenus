// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/Camera/MCameraComponent.h"
#include "Characters/Interfaces/MStamina.h"
#include "Kismet/KismetMathLibrary.h"

void UMCameraComponent::BeginPlay()
{
	Super::BeginPlay();
	GammaWithNormalStamina = PostProcessSettings.ColorGamma;
	BloomIntensityWithNormalStamina = PostProcessSettings.BloomIntensity;
	VignetteIntensityWithNormalStamina = PostProcessSettings.VignetteIntensity;
}

void UMCameraComponent::SetStamina(IMStamina* InStamina)
{
	Stamina = InStamina;
	check(Stamina);
	Stamina->OnChangedStamina().AddUObject(this, &ThisClass::StaminaEffects);
}

void UMCameraComponent::StaminaEffects()
{
	check(Stamina);
	const float CurrentStamina = Stamina->GetCurrentStamina();
	if (CurrentStamina < StartValueForStaminaEffects)
	{
		const float Aplha = UKismetMathLibrary::MapRangeClamped(CurrentStamina, 0, StartValueForStaminaEffects, 0, 1);
		const FVector4d GammaValue = FMath::Lerp(GammaWithMinStamina, GammaWithNormalStamina, Aplha);
		const float BloomIntensityValue = FMath::Lerp(BloomIntensityWithMinStamina, BloomIntensityWithNormalStamina, Aplha);
		const float VignetteIntensityValue = FMath::Lerp(VignetteIntensityWithMinStamina, VignetteIntensityWithNormalStamina, Aplha);
		PostProcessSettings.ColorGamma = GammaValue;
		PostProcessSettings.BloomIntensity = BloomIntensityValue;
		PostProcessSettings.VignetteIntensity = VignetteIntensityValue;
	}
}
