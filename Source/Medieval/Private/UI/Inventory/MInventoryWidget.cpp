// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Inventory/MInventoryWidget.h"
#include "Components/PanelWidget.h"
#include "Characters/Interfaces/MEquipment.h"
#include "Core/Interfaces/MInventory.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "UI/Inventory/MInventorySlotWidget.h"
#include "UI/Inventory/Strategies/MInventoryStrategy.h"

void UMInventoryWidget::SetInventory(IMInventory* InInventory)
{
	check(InInventory);
	Inventory = InInventory;
	Inventory->OnInvetoryChanged().AddUObject(this, &ThisClass::Update);
	Update();
}

void UMInventoryWidget::SetStrategy(UMInventoryStrategy* InStrategy)
{
	Strategy = InStrategy;
}

void UMInventoryWidget::Update()
{
	Super::Update();
	check(Inventory);
	check(PanelWidget);
	check(InventorySlotWidgetClass);

	Equipments = FMHelperFunctions::GetComponentsByInterface<IMEquipment>(GetOwningPlayerPawn());

	PanelWidget->ClearChildren();
	const TMap<FName, uint32>& Items = Inventory->GetItems();
	for (const TPair<FName, uint32>& Item : Items)
	{
		UMInventorySlotWidget* InventorySlotWidget = CreateWidget<UMInventorySlotWidget>(this, InventorySlotWidgetClass);
		check(InventorySlotWidget);

		const FMItemSlot ItemSlot{ Item.Key, Item.Value, IsEquipped(Item.Key) };
		InventorySlotWidget->SetItem(ItemSlot);
		InventorySlotWidget->OnInventorySlotClicked.AddUObject(this, &ThisClass::InventorySlotClicked);

		PanelWidget->AddChild(InventorySlotWidget);
	}
}

bool UMInventoryWidget::IsEquipped(const FName& RowName)
{
	for (const IMEquipment* Equipment : Equipments)
	{
		check(Equipment);
		if (Equipment->GetEquippedItemRowName().IsEqual(RowName)) return true;
	}
	return false;
}

void UMInventoryWidget::InventorySlotClicked(const FName& RowName)
{
	check(Strategy);
	Strategy->ClickedItem(RowName);
	Update();
}