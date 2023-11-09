// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"

enum class EMItemType : uint8;
class UDataTable;
class UStaticMesh;
struct FMItemInfo;

class MEDIEVAL_API FMItemHelper final
{
public:
	static const UDataTable* GetDataTable();
	static FMItemInfo* GetItemInfo(const FName& RowName);
	static FText GetItemName(const FName& RowName);
	static EMItemType GetItemType(const FName& RowName);
	static UStaticMesh* GetItemStaticMesh(const FName& RowName);
	static USkeletalMesh* GetItemSkeletalMesh(const FName& RowName);
	static TSubclassOf<UAnimInstance> GetItemAnimInstanceMesh(const FName& RowName);
	static float GetDamage(const FName& RowName);
	static float GetPrice(const FName& RowName);
};
