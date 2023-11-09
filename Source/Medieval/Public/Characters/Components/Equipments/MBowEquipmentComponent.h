// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Interfaces/MBowFighting.h"
#include "Characters/Components/Equipments/MWeaponEquipmentComponent.h"
#include "MBowEquipmentComponent.generated.h"

class IMCameraShakeSource;
class IMStamina;

UCLASS()
class MEDIEVAL_API UMBowEquipmentComponent final: public UMWeaponEquipmentComponent, public IMBowFighting
{
	GENERATED_BODY()
	
public:
	UMBowEquipmentComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void StartCharge() override;
	virtual void StopCharge() override;
	virtual void Fire() override;
	virtual float GetCharge() const override;
	void SetCameraShakeSource(IMCameraShakeSource* InCameraShakeSource);
	void SetStamina(IMStamina* InStamina);


private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	float StaminaUsageWhileChargingPerSecond = 10.0f;

	IMCameraShakeSource* CameraShakeSource;
	IMStamina* Stamina;

	IMBowFighting* GetBowFighting() const;
};
