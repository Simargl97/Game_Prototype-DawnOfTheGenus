// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MInventory.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnInvetoryChanged)
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnAddedItem, const FName&, const uint32);
DECLARE_MULTICAST_DELEGATE_TwoParams(FOnRemoveItem, const FName&, const uint32);

UINTERFACE(MinimalAPI)
class UMInventory : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMInventory
{
	GENERATED_BODY()

public:
	virtual void AddItem(const FName& RowName, const uint32 Count = 1) = 0;
	virtual void TransferFromInventory(IMInventory* OtherInventory) = 0;
	virtual const TMap<FName, uint32>& GetItems() const = 0;
	virtual bool HasItem(const FName& RowName) const = 0;
	virtual uint32 GetCountByRowName(const FName& RowName) const = 0;
	virtual bool RemoveItem(const FName& RowName, const uint32 Count = 1) = 0;
	virtual FOnInvetoryChanged& OnInvetoryChanged() = 0;
	virtual FOnAddedItem& OnAddedItem() = 0;
	virtual FOnRemoveItem& OnRemoveItem() = 0;
};
