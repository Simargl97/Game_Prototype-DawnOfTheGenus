// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MActorComponent.generated.h"


UCLASS(Abstract)
class MEDIEVAL_API UMActorComponent : public UActorComponent
{
	GENERATED_BODY()

protected:
	FTimerManager& GetWorldTimerManager() const;
}; 
