// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/Equipments/MWeaponEquipmentComponent.h"

void UMWeaponEquipmentComponent::ToggleCombatMode()
{
	if (IsEquipped())
	{
		bIsCombatMode ? StopCombatMode() : StartCombatMode();
	}
}

void UMWeaponEquipmentComponent::StopCombatMode()
{
	bIsCombatMode = false;
	AttachActorToSceneComponent();
}

void UMWeaponEquipmentComponent::StartCombatMode()
{
	bIsCombatMode = true;
	AttachActorToSceneComponent(CombatEquippedSceneComponent);
}

bool UMWeaponEquipmentComponent::isCombatMode() const
{
	return bIsCombatMode;
}

void UMWeaponEquipmentComponent::SetCombatEquippedSceneComponent(USceneComponent* InCombatEquippedSceneComponent)
{
	CombatEquippedSceneComponent = InCombatEquippedSceneComponent;
}

void UMWeaponEquipmentComponent::UnEquip()
{
	Super::UnEquip();
	StopCombatMode();
}