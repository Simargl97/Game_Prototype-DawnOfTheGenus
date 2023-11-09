// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MEquipment.generated.h"

UINTERFACE(MinimalAPI)
class UMEquipment : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMEquipment
{
	GENERATED_BODY()

public:
	virtual void ToggleEquip(const FName& RowName) = 0;
	virtual FName GetEquippedItemRowName() const = 0;
};
