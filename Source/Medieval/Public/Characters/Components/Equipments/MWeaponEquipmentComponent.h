// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Components/Equipments/MEquipmentComponent.h"
#include "MWeaponEquipmentComponent.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API UMWeaponEquipmentComponent : public UMEquipmentComponent
{
	GENERATED_BODY()
	
public:
	void ToggleCombatMode();
	bool isCombatMode() const;
	void SetCombatEquippedSceneComponent(USceneComponent* InCombatEquippedSceneCOmponent);

protected:
	virtual void UnEquip() override;

private:
	UPROPERTY()
	USceneComponent* CombatEquippedSceneComponent;

	bool bIsCombatMode;

	void StartCombatMode();
	void StopCombatMode();

};
