// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "MStartingItemsComponent.generated.h"

USTRUCT(BlueprintType)
struct FStartingItems
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FDataTableRowHandle ItemRow;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0", ClampMax = "1", UIMax = "1"))
	float Probability = 1.0f;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
	uint32 Count = 1;
};

UCLASS()
class MEDIEVAL_API UMStartingItemsComponent : public UMActorComponent
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TArray<FStartingItems> StartingItems;

	void AddStartingItems();
};
