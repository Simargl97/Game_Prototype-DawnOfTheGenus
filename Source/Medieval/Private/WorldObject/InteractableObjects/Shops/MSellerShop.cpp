// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/InteractableObjects/Shops/MSellerShop.h"
#include "Core/Helpers/MItemHelper.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "Core/Interfaces/MInventory.h"

void AMSellerShop::DoInteract(AActor* OtherActor)
{
	Super::DoInteract(OtherActor);
	IMInventory* Inventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(OtherActor);
	if (Inventory)
	{
		if (Inventory->RemoveItem(GetCoinRowName(), GetNeedCoins()))
		{
			const TArray<FDataTableRowHandle>& SellingItems = GetItems();
			for (const FDataTableRowHandle& Item : SellingItems)
			{
				Inventory->AddItem(Item.RowName);
			}
		}
	}
}

float AMSellerShop::GetNeedCoins() const
{
	const TArray<FDataTableRowHandle>& SellingItems = GetItems();
	float NeedCoins = 0.0f;
	for (const FDataTableRowHandle& Item : SellingItems)
	{
		NeedCoins += FMItemHelper::GetPrice(Item.RowName);
	}
	return NeedCoins;
}
