// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "MCameraComponent.generated.h"

class IMStamina;

UCLASS()
class MEDIEVAL_API UMCameraComponent : public UCameraComponent
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	void SetStamina(IMStamina* InStamina);

private:

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	float StartValueForStaminaEffects = 50.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FVector4d GammaWithMinStamina { 0.8f, 0.8f, 1.0f, 1.0f };

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	float BloomIntensityWithMinStamina = 8.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	float VignetteIntensityWithMinStamina = 1.0f;

	IMStamina* Stamina;
	FVector4d GammaWithNormalStamina;
	float BloomIntensityWithNormalStamina;
	float VignetteIntensityWithNormalStamina;

	void StaminaEffects();
	
};
