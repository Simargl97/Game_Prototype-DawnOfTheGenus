// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MBowFighting.generated.h"

UINTERFACE(MinimalAPI)
class UMBowFighting : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMBowFighting
{
	GENERATED_BODY()

public:
	virtual void StartCharge() = 0;
	virtual void StopCharge() = 0;
	virtual void Fire() = 0;
	virtual float GetCharge() const = 0;
};
