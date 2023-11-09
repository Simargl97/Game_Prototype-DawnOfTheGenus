// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraShakeSourceComponent.h"
#include "Characters/Interfaces/MCameraShakeSource.h"
#include "MCameraShakeSourceComponent.generated.h"

class IMStamina;

UCLASS()
class MEDIEVAL_API UMCameraShakeSourceComponent final: public UCameraShakeSourceComponent, public IMCameraShakeSource
{
	GENERATED_BODY()
	
public:
	virtual void StartShaking() override;
	virtual void StopShaking() override;
	void SetStamina(IMStamina* InStamina);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0.05", UIMin = "0.05", ClampMax = "1.0", UIMax = "1.0"))
	float Treshhold = 0.1f;

	IMStamina* Stamina;
	float LastScale = 0.0f;

	void StaminaEffects();
	float GetScale() const;
};
