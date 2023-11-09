// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Pause/MPauseWidget.h"
#include "Characters/Interfaces/MHUDPlayerController.h"
#include "UI/Base/MMButton.h"
#include "GameInstance/Interfaces/MGameState.h"

void UMPauseWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(ContinueButton);
	check(ReturnToMainMenuButton);
	check(QuitGameButton);

	ContinueButton->OnClicked().AddDynamic(this, &ThisClass::ContinueGameClicked);
	ReturnToMainMenuButton->OnClicked().AddDynamic(this, &ThisClass::ReturnToMainMenuClicked);
	QuitGameButton->OnClicked().AddDynamic(this, &ThisClass::QuitGameClicked);
}

void UMPauseWidget::ContinueGameClicked()
{
	IMHUDPlayerController* HUDPlayerController = Cast<IMHUDPlayerController>(GetOwningPlayer());
	check(HUDPlayerController);
	HUDPlayerController->ContinueGame();
}

void UMPauseWidget::ReturnToMainMenuClicked()
{
	check(GetGameState());
	GetGameState()->ReturnToMainMenu();
}

void UMPauseWidget::QuitGameClicked()
{
	check(GetGameState());
	GetGameState()->QuitGame();
}
