// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/HUD/MMainMenuHUDWidget.h"
#include "UI/Base/MMButton.h"
#include "GameInstance/Interfaces/MGameState.h"

void UMMainMenuHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(NewGameButton);
	check(QuitGameButton);

	NewGameButton->OnClicked().AddDynamic(this, &ThisClass::NewGameClicked);
	QuitGameButton->OnClicked().AddDynamic(this, &ThisClass::QuitGameClicked);

}

void UMMainMenuHUDWidget::NewGameClicked()
{
	check(GetGameState());
	GetGameState()->NewGame();
}

void UMMainMenuHUDWidget::QuitGameClicked()
{
	check(GetGameState());
	GetGameState()->QuitGame();
}
