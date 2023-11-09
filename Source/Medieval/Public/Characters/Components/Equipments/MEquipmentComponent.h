// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Interfaces/MEquipment.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "MEquipmentComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMEquipmentComponent : public UMActorComponent, public IMEquipment
{
	GENERATED_BODY()
	
public:
	virtual void ToggleEquip(const FName& RowName) override;
	virtual FName GetEquippedItemRowName() const override;
	void SetEquippedSceneComponent(USceneComponent* InEquippedSceneCOmponent);

protected:
	virtual void Equip(const FName& RowName);
	virtual void UnEquip();
	void AttachActorToSceneComponent(USceneComponent* InEquippedSceneComponent = nullptr) const;
	bool IsEquipped() const;
	AActor* GetEquippedActor() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<AActor> EquippedActorClass;

	UPROPERTY()
	AActor* EquippedActor;

	UPROPERTY()
	USceneComponent* EquippedSceneComponent;

	FName EquippedItemRowName;
};