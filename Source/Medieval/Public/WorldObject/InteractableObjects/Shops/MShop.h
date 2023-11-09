// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "WorldObject/InteractableObjects/MMInteractableObject.h"
#include "MShop.generated.h"


UCLASS(Abstract)
class MEDIEVAL_API AMShop : public AMMInteractableObject
{
	GENERATED_BODY()
	
public:
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual FText GetObjectName() const;
	const TArray<FDataTableRowHandle>& GetItems() const;
	FName GetCoinRowName() const;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Main")
	FDataTableRowHandle CoinRow;

	UPROPERTY(EditAnywhere, Category = "Settings|Main")
	TArray<FDataTableRowHandle> Items;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Main")
	FText ActionText;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Main")
	FString ItemSeparatorText{TEXT(", ")};
};
