// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/InteractableObjects/Shops/MBuyerShop.h"
#include "Core/Helpers/MItemHelper.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "Core/Interfaces/MInventory.h"

void AMBuyerShop::DoInteract(AActor* OtherActor)
{
	Super::DoInteract(OtherActor);
	IMInventory* Inventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(OtherActor);
	if (Inventory)
	{
		const TArray<FDataTableRowHandle>& ByingItems = GetItems();
		for (const FDataTableRowHandle& Item : ByingItems)
		{
			const float Price = FMItemHelper::GetPrice(Item.RowName);
			const uint32 Count = Inventory->GetCountByRowName(Item.RowName);
			if (Count > 0) 
			{
				Inventory->RemoveItem(Item.RowName, Count);
				Inventory->AddItem(GetCoinRowName(), Count * Price);
			}
		}
	}
}
