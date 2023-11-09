// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MCameraShakeSource.generated.h"


UINTERFACE(MinimalAPI)
class UMCameraShakeSource : public UInterface
{
	GENERATED_BODY()
};


class MEDIEVAL_API IMCameraShakeSource
{
	GENERATED_BODY()

public:
	virtual void StartShaking() = 0;
	virtual void StopShaking() = 0;
};
