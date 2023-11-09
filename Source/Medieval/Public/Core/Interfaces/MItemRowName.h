// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MItemRowName.generated.h"

UINTERFACE(MinimalAPI)
class UMItemRowName : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMItemRowName
{
	GENERATED_BODY()


public:
	virtual void SetRowName(const FName& InRowName) = 0;
	virtual FName GetRowName() const = 0;
};
