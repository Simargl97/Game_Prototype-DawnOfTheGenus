// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Inventory/Strategies/MPlayerInventoryStrategy.h"
#include "Core/Helpers/MItemHelper.h"
#include "Characters/Interfaces/MEquipment.h"

void UMPlayerInventoryStrategy::ClickedItem(const FName& RowName) const
{
	Super::ClickedItem(RowName);
	check(Player);

	const EMItemType ItemType = FMItemHelper::GetItemType(RowName);
	if (ItemTypesAndEquipmentClasssesMatching.Contains(ItemType))
	{
		const TSubclassOf<UMEquipmentComponent> EquipmentClass = ItemTypesAndEquipmentClasssesMatching[ItemType];
		IMEquipment* Equipment = Cast<IMEquipment>(Player->GetComponentByClass(EquipmentClass));
		Equipment->ToggleEquip(RowName);
	}
}

void UMPlayerInventoryStrategy::SetPlayer(AActor* InPlayer)
{
	Player = InPlayer;

}
