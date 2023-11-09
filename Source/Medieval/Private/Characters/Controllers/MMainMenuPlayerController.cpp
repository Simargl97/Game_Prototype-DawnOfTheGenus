// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Controllers/MMainMenuPlayerController.h"

void AMMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	SetInputMode(FInputModeUIOnly());
}
