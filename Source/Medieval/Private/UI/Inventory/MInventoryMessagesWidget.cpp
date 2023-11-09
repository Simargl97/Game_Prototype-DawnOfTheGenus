// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Inventory/MInventoryMessagesWidget.h"
#include "Core/Interfaces/MInventory.h"
#include "Core/Helpers/MItemHelper.h"
#include "UI/Inventory/Messages/MInventoryMessageWidget.h"


void UMInventoryMessagesWidget::SetInventory(IMInventory* InInventory)
{
	check(InInventory);
	Inventory = InInventory;
	Inventory->OnAddedItem().AddUObject(this, &ThisClass::AddedItem);
	Inventory->OnRemoveItem().AddUObject(this, &ThisClass::RemoveItem);
}

void UMInventoryMessagesWidget::AddedItem(const FName& RowName, const uint32 Count)
{
	AddInventoryMessageWidget(RowName, Count);
}

void UMInventoryMessagesWidget::AddInventoryMessageWidget(const FName& RowName, const int32 Count)
{
	check(PanelWidget);
	check(Inventory);
	check(InventoryMessageWidgetClass);
	UMInventoryMessageWidget* InventoryMessageWidget = CreateWidget<UMInventoryMessageWidget>(this, InventoryMessageWidgetClass);
	check(InventoryMessageWidget);

	InventoryMessageWidget->SetItemName(FMItemHelper::GetItemName(RowName));
	InventoryMessageWidget->SetItemsCount(Count);
	InventoryMessageWidget->SetItemsTotal(Inventory->GetCountByRowName(RowName));

	PanelWidget->AddChild(InventoryMessageWidget);
}

void UMInventoryMessagesWidget::RemoveItem(const FName& RowName, const uint32 Count)
{
	AddInventoryMessageWidget(RowName, -1 * Count);
}