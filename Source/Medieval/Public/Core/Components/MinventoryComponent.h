// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "Core/Interfaces/MInventory.h"
#include "MinventoryComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMinventoryComponent final: public UMActorComponent, public IMInventory
{
	GENERATED_BODY()
	
public:
	virtual void AddItem(const FName& RowName, const uint32 Count = 1) override;
	virtual void TransferFromInventory(IMInventory* OtherInventory) override;
	virtual const TMap<FName, uint32>& GetItems() const override;
	virtual bool HasItem(const FName& RowName) const override;
	virtual uint32 GetCountByRowName(const FName& RowName) const override;
	virtual bool RemoveItem(const FName& RowName, const uint32 Count = 1) override;
	virtual FOnInvetoryChanged& OnInvetoryChanged() override;
	virtual FOnAddedItem& OnAddedItem() override;
	virtual FOnRemoveItem& OnRemoveItem() override;

private:
	TMap<FName, uint32> Items;
	FOnInvetoryChanged OnInventoryChangedEvent;
	FOnAddedItem OnAddedItemEvent;
	FOnRemoveItem OnRemoveItemEvent;
};
