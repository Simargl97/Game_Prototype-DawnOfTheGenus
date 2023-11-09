// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/HUD/MHUDWidget.h"
#include "GameInstance/Interfaces/MGameState.h"
#include "UI/MLoadingScreenWidget.h"

void UMHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(LoadingScreenWidget);

	IMGameState* GameState = GetGameState();
	check(GameState);
	GameState->OnLevelStartedLoading().AddUObject(LoadingScreenWidget, &ThisClass::Show);
	GameState->OnLevelLoaded().AddUObject(LoadingScreenWidget, &ThisClass::Hide);
}
