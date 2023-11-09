// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/InteractableObjects/Shops/MShop.h"
#include "Kismet/KismetStringLibrary.h"
#include "Core/Helpers/MItemHelper.h"

void AMShop::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	CoinRow.DataTable = FMItemHelper::GetDataTable();

	for (FDataTableRowHandle& Item : Items)
	{
		Item.DataTable = FMItemHelper::GetDataTable();
	}
}

FText AMShop::GetObjectName() const
{
	TArray<FString> ItemNames;
	for (const FDataTableRowHandle& Item : Items)
	{
		const FText ItemName = FMItemHelper::GetItemName(Item.RowName);
		ItemNames.Add(ItemName.ToString());
	}
	const FText ItemNamesText = FText::FromString(UKismetStringLibrary::JoinStringArray(ItemNames, ItemSeparatorText));
	return FText::Format(FTextFormat::FromString("{0}: {1}"), ActionText, ItemNamesText);
}

const TArray<FDataTableRowHandle>& AMShop::GetItems() const
{
	return Items;
}

FName AMShop::GetCoinRowName() const
{
	return CoinRow.RowName;
}
