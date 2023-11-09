// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/Equipments/MBowEquipmentComponent.h"
#include "Characters/Interfaces/MCameraShakeSource.h"
#include "Characters/Interfaces/MStamina.h"

UMBowEquipmentComponent::UMBowEquipmentComponent() : Super()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMBowEquipmentComponent::BeginPlay()
{
	Super::BeginPlay();
	SetComponentTickEnabled(false);
}

void UMBowEquipmentComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	check(Stamina);
	Stamina->UseStamina(StaminaUsageWhileChargingPerSecond * DeltaTime);
}

void UMBowEquipmentComponent::StartCharge()
{
	if (GetBowFighting())
	{
		check(CameraShakeSource);
		GetBowFighting()->StartCharge();
		CameraShakeSource->StartShaking();
		SetComponentTickEnabled(true);
	}
}

void UMBowEquipmentComponent::StopCharge()
{
	if (GetBowFighting())
	{
		check(CameraShakeSource);
		GetBowFighting()->StopCharge();
		CameraShakeSource->StopShaking();
		SetComponentTickEnabled(false);
	}
}

void UMBowEquipmentComponent::Fire()
{
	if (GetBowFighting())
	{
		GetBowFighting()->Fire();
	}
}

float UMBowEquipmentComponent::GetCharge() const
{
	if (GetBowFighting())
	{
		return GetBowFighting()->GetCharge();
	}
	return 0.0f;
}

void UMBowEquipmentComponent::SetCameraShakeSource(IMCameraShakeSource* InCameraShakeSource)
{
	CameraShakeSource = InCameraShakeSource;
}

void UMBowEquipmentComponent::SetStamina(IMStamina* InStamina)
{
	Stamina = InStamina;
}

IMBowFighting* UMBowEquipmentComponent::GetBowFighting() const
{
	return 	Cast<IMBowFighting>(GetEquippedActor());
}