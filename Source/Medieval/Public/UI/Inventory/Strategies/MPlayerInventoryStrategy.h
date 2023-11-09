// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/Inventory/Strategies/MInventoryStrategy.h"
#include "MPlayerInventoryStrategy.generated.h"

enum class EMItemType : uint8;
class UMEquipmentComponent;

UCLASS(Abstract, Blueprintable)
class MEDIEVAL_API UMPlayerInventoryStrategy : public UMInventoryStrategy
{
	GENERATED_BODY()
	
public:
	virtual void ClickedItem(const FName& RowName) const override;
	void SetPlayer(AActor* InPlayer);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TMap<EMItemType, TSubclassOf<UMEquipmentComponent>> ItemTypesAndEquipmentClasssesMatching;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	AActor* Player;
};
