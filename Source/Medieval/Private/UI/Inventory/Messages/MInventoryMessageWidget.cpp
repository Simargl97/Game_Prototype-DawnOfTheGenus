// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Inventory/Messages/MInventoryMessageWidget.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UMInventoryMessageWidget::NativeConstruct()
{
	Super::NativeConstruct();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::RemoveFromParent, DelayBeforeRemove);
}

void UMInventoryMessageWidget::SetItemName(const FText& ItemName) const
{
	check(ItemNameTextBlock);
	ItemNameTextBlock->SetText(ItemName);
}

void UMInventoryMessageWidget::SetItemsCount(const int32 ItemsCount) const
{
	check(ItemsCountTextBlock);
	ItemsCountTextBlock->SetText(FText::AsNumber(FMath::Abs(ItemsCount)));
	SetType(ItemsCount > 0);
}

void UMInventoryMessageWidget::SetType(const bool bIsAdded) const
{
	check(PlusImage);
	check(MinusImage);
	if (bIsAdded)
	{
		MinusImage->SetVisibility(ESlateVisibility::Collapsed);
		PlusImage->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		MinusImage->SetVisibility(ESlateVisibility::Visible);
		PlusImage->SetVisibility(ESlateVisibility::Collapsed);
	}
}

void UMInventoryMessageWidget::SetItemsTotal(const uint32 ItemsTotal) const
{
	check(ItemNameTextBlock);
	ItemsTotalTextBlock->SetText(FText::AsNumber(ItemsTotal));
}