// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MHUDPlayerController.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnTogglewWidget)

UINTERFACE(MinimalAPI)
class UMHUDPlayerController : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMHUDPlayerController
{
	GENERATED_BODY()

public:
	virtual void ContinueGame() = 0;
	virtual FOnTogglewWidget& OnToggleInventoryWidget() = 0;
	virtual FOnTogglewWidget& OnTogglePauseWidget() = 0;
};
