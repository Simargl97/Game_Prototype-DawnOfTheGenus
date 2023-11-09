// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MInventoryStrategy.generated.h"


UCLASS(Abstract, Blueprintable)
class MEDIEVAL_API UMInventoryStrategy : public UObject
{
	GENERATED_BODY()
	
public:
	virtual void ClickedItem(const FName& RowName) const;
};
