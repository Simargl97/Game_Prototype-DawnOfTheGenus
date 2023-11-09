// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/Helpers/MItemHelper.h"
#include "Core/BaseTypes/MCoreTypes.h"
#include "Core/Helpers/MDataTableHelper.h"
#include "Core/Settings/MGameSettings.h"

const UDataTable* FMItemHelper::GetDataTable()
{
	const UMGameSettings* GameSettings = GetDefault<UMGameSettings>();
	check(GameSettings);
	return GameSettings->ItemsDataTable.LoadSynchronous();
}

FMItemInfo* FMItemHelper::GetItemInfo(const FName& RowName)
{
	return FMDataTableHelper::FindRow<FMItemInfo>(GetDataTable(), RowName);
}

FText FMItemHelper::GetItemName(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->Name;
	
}

EMItemType FMItemHelper::GetItemType(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->ItemType;
}

UStaticMesh* FMItemHelper::GetItemStaticMesh(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->StaticMesh;
}

USkeletalMesh* FMItemHelper::GetItemSkeletalMesh(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->SkeletalMesh;
}

TSubclassOf<UAnimInstance> FMItemHelper::GetItemAnimInstanceMesh(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->AnimInstanceClass;
}

float FMItemHelper::GetDamage(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->Damage;
}

float FMItemHelper::GetPrice(const FName& RowName)
{
	const FMItemInfo* ItemInfo = GetItemInfo(RowName);
	check(ItemInfo);
	return ItemInfo->Price;
}
