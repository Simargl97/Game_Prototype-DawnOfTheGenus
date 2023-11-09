// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Inventory/MInventorySlotWidget.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Core/BaseTypes/MCoreTypes.h"
#include "Core/Helpers/MItemHelper.h"

void UMInventorySlotWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(InventorySlotButton);
	InventorySlotButton->OnClicked.AddUniqueDynamic(this, &ThisClass::InventorySlotClicked);
}

void UMInventorySlotWidget::InventorySlotClicked()
{
	OnInventorySlotClicked.Broadcast(ItemSlot.RowName);
}

void UMInventorySlotWidget::SetItem(const FMItemSlot& InItemSlot)
{
	check(Thumbnail);
	check(ItemName);

	ItemSlot = InItemSlot;
	const FMItemInfo* ItemInfo = FMItemHelper::GetItemInfo(ItemSlot.RowName);
	check(ItemInfo)

	Thumbnail->SetBrushFromTexture(ItemInfo->Thumbnail);
	ItemName->SetText(GetItemNameText(ItemInfo->Name));
}

FText UMInventorySlotWidget::GetItemNameText(const FText& Name) const
{

	return FText::Format(FTextFormat::FromString("{0} x {1}"), Name, ItemSlot.Count);
}

bool UMInventorySlotWidget::IsActive() const
{
	return ItemSlot.bIsActive;
}