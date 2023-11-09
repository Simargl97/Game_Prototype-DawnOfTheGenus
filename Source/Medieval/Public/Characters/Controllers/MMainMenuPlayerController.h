// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Controllers/MPlayerController.h"
#include "MMainMenuPlayerController.generated.h"

UCLASS()
class MEDIEVAL_API AMMainMenuPlayerController final: public AMPlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay();
};
