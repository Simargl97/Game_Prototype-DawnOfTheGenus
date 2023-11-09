// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MGameState.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnLevelStartedLoading);
DECLARE_MULTICAST_DELEGATE(FOnLevelLoaded);

UINTERFACE(MinimalAPI)
class UMGameState : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMGameState
{
	GENERATED_BODY()

public:
	virtual void NewGame() = 0;
	virtual void ReturnToMainMenu() = 0;
	virtual void QuitGame() const = 0;
	virtual void LevelLoaded() = 0;
	virtual FOnLevelStartedLoading& OnLevelStartedLoading() = 0;
	virtual FOnLevelLoaded& OnLevelLoaded() = 0;
};
