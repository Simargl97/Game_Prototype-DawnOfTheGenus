// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/Components/MStartingItemsComponent.h"
#include "Core/Helpers/\MHelperFunctions.h"
#include "Core/Interfaces/MInventory.h"
#include "Kismet/KismetMathLibrary.h"

void UMStartingItemsComponent::BeginPlay()
{
	Super::BeginPlay();
	AddStartingItems();
}

void UMStartingItemsComponent::AddStartingItems()
{

	IMInventory* Inventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(GetOwner());
	check(Inventory);

	for (const FStartingItems& StartingItem : StartingItems)
	{
		for (uint32 i = 0; i < StartingItem.Count; ++i)
		{
			if (UKismetMathLibrary::RandomBoolWithWeight(StartingItem.Probability))
			{
				Inventory->AddItem(StartingItem.ItemRow.RowName);
			}
		}
	}

}
