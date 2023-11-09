// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Interfaces/MBowFighting.h"
#include "WorldObject/Weapons/MWeapon.h"
#include "MBow.generated.h"

class IMInventory;
class AMArrow;
class UTimelineComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMBow final: public AMWeapon, public IMBowFighting
{
	GENERATED_BODY()
	
public:
	AMBow();
	virtual void StartCharge() override;
	virtual void StopCharge() override;
	virtual void Fire() override;
	virtual float GetCharge() const override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* ChargeAudioComponent;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Arrow")
	UCurveFloat* ChargeCurve;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Arrow")
	TSubclassOf<AMArrow> ArrowClass;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Arrow")
	FName ArrowSocketName;
	
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Arrow")
	FName ArrowRowName;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Sounds")
	USoundBase* FireSound;

	UPROPERTY()
	AMArrow* Arrow;

	UPROPERTY()
	UTimelineComponent* ChargeTimeline;

	IMInventory* OwnerInventory;
	FTimerHandle TimerHandle;
	float Charge = 0.0f;

	UFUNCTION()
	void ProgressCharge(const float Value);
};
