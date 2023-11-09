// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MInventoryMessagesWidget.generated.h"

class IMInventory;
class UMInventoryMessageWidget;

UCLASS(Abstract)
class MEDIEVAL_API UMInventoryMessagesWidget final: public UMUserWidget
{
	GENERATED_BODY()
	
public:
	void SetInventory(IMInventory* IInnventory);

protected:
	UPROPERTY(meta = (BindWidget))
	UPanelWidget* PanelWidget;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<UMInventoryMessageWidget> InventoryMessageWidgetClass;

	IMInventory* Inventory;

	void AddedItem(const FName& RowName, const uint32 Count);
	void RemoveItem(const FName& RowName, const uint32 Count);
	void AddInventoryMessageWidget(const FName& RowName, const int32 Count);
};
