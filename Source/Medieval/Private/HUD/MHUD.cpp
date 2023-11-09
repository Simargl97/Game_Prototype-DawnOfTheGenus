// Copyright (c). Medieval . Author: Sergoe Osipchuk

#include "HUD/MHUD.h"
#include "Blueprint/UserWidget.h"

void AMHUD::BeginPlay()
{
	Super::BeginPlay();
	UUserWidget* UserWidget = CreateWidget<UUserWidget>(GetOwningPlayerController(), HUDWidgetClass);
	check(UserWidget);
	UserWidget->AddToViewport();
}
