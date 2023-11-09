// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MInteractData.generated.h"

UINTERFACE(MinimalAPI)
class UMInteractData : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMInteractData
{
	GENERATED_BODY()

	
public:
	virtual void SetObjectName(const FText& ObjectName) const = 0;
	virtual void SetInteractText(const FText& InteractText) const = 0;

};
