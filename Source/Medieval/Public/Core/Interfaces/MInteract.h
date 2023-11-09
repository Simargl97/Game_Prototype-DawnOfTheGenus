// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MInteract.generated.h"

UINTERFACE(MinimalAPI)
class UMInteract : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMInteract
{
	GENERATED_BODY()

public:
	virtual void Interact(AActor* OtherActor) = 0;
	virtual void OnEnter() = 0;
	virtual void OnLeave() = 0;
};
