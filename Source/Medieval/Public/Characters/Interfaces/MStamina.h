// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MStamina.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnChangedStamina);
DECLARE_MULTICAST_DELEGATE(FOnRanOutStamina);

UINTERFACE(MinimalAPI)
class UMStamina : public UInterface
{
	GENERATED_BODY()
};


class MEDIEVAL_API IMStamina
{
	GENERATED_BODY()

public:
	virtual void UseStamina(const float UsedStamina) = 0;
	virtual float GetCurrentStamina() const = 0;
	virtual float GetPercentStamina() const = 0;
	virtual FOnChangedStamina& OnChangedStamina() = 0;
	virtual FOnRanOutStamina& OnRanOutStamina() = 0;
};
