// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/Components/MinventoryComponent.h"

void UMinventoryComponent::AddItem(const FName& RowName, const uint32 Count)
{
	check(!RowName.IsNone());
	check(Count > 0);
	if (Items.Contains(RowName))
	{
		Items[RowName] += Count;
	}
	else
	{
		Items.Add(RowName, Count);
	}
	OnInventoryChangedEvent.Broadcast();
	OnAddedItemEvent.Broadcast(RowName, Count);
}

void UMinventoryComponent::TransferFromInventory(IMInventory* OtherInventory)
{
	check(OtherInventory);
	const TMap<FName, uint32> OtherItems = OtherInventory->GetItems();

	for (const TPair<FName, uint32>& Pair : OtherItems)
	{
		AddItem(Pair.Key, Pair.Value);
		if (!OtherInventory->RemoveItem(Pair.Key, Pair.Value))
		{
			checkNoEntry();
		}
	}
}

const TMap<FName, uint32>& UMinventoryComponent::GetItems() const
{
	return Items;
}

bool UMinventoryComponent::HasItem(const FName& RowName) const
{
	return Items.Contains(RowName);
}

uint32 UMinventoryComponent::GetCountByRowName(const FName& RowName) const
{
	if (HasItem(RowName))
	{
		return Items[RowName];
	}
	return 0;
}

bool UMinventoryComponent::RemoveItem(const FName& RowName, const uint32 Count)
{
	if (!Items.Contains(RowName)) return false;
	if (Items[RowName] < Count) return false;

	Items[RowName] -= Count;
	if (Items[RowName] == 0)
	{
		Items.Remove(RowName);
	}
	OnInventoryChangedEvent.Broadcast();
	OnRemoveItemEvent.Broadcast(RowName, Count);
	return true;
}

FOnInvetoryChanged& UMinventoryComponent::OnInvetoryChanged()
{
	return OnInventoryChangedEvent;
}

FOnAddedItem& UMinventoryComponent::OnAddedItem()
{
	return OnAddedItemEvent;
}

FOnRemoveItem& UMinventoryComponent::OnRemoveItem()
{
	return OnRemoveItemEvent;
}