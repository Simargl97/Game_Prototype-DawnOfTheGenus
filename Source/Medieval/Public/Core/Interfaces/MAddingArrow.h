// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MAddingArrow.generated.h"

UINTERFACE(MinimalAPI)
class UMAddingArrow : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMAddingArrow
{
	GENERATED_BODY()

public:
	virtual void AddArrow(AActor* Arrow) = 0;
};
