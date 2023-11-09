// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MInventoryWidget.generated.h"

class IMEquipment;
class IMInventory;
class UMInventorySlotWidget;
class UMInventoryStrategy;

UCLASS(Abstract)
class MEDIEVAL_API UMInventoryWidget final: public UMUserWidget
{
	GENERATED_BODY()
	
public:
	void SetInventory(IMInventory* InInventory);
	void SetStrategy(UMInventoryStrategy* InStrategy);

protected:
	UPROPERTY(meta = (BindWidget))
	UPanelWidget* PanelWidget;

	virtual void Update() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<UMInventorySlotWidget> InventorySlotWidgetClass;

	TArray<IMEquipment*> Equipments;
	IMInventory* Inventory;

	UPROPERTY()
	UMInventoryStrategy* Strategy;

	bool IsEquipped(const FName& RowName);
	void InventorySlotClicked(const FName& RowName);
};
