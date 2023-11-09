// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Controllers/MGamePlayerController.h"
#include "Characters/Interfaces/MMovement.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "Core/Settings/MGameSettings.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

void AMGamePlayerController::ContinueGame()
{
	TogglePauseWidget();
}

void AMGamePlayerController::TogglePauseWidget()
{
	bIsPauseShown = !bIsPauseShown;
	SetPause(bIsPauseShown);
	UpdateInputMode();
	OnTogglePauseWidgetEvent.Broadcast();
}

void AMGamePlayerController::UpdateInputMode()
{
	bShowMouseCursor = bIsInventoryShown || bIsPauseShown;
	if (bShowMouseCursor)
	{
		SetInputMode(FInputModeGameAndUI().SetHideCursorDuringCapture(false));
	}
	else
	{
		SetInputMode(FInputModeGameOnly());
	}
}

void AMGamePlayerController::BeginPlay()
{
	Super::BeginPlay();
	UpdateInputMode();

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->ClearAllMappings();

		const UMGameSettings* GameSettings = GetDefault<UMGameSettings>();
		check(GameSettings);
		Subsystem->AddMappingContext(GameSettings->InputMappingContext.LoadSynchronous(), 0);
	}
}

void AMGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	check(EnhancedInputComponent);
	check(InventoryAction);
	check(PauseAction);

	EnhancedInputComponent->BindAction(InventoryAction, ETriggerEvent::Started, this, &ThisClass::ToggleInventoryWidget);
	EnhancedInputComponent->BindAction(PauseAction, ETriggerEvent::Started, this, &ThisClass::TogglePauseWidget);
}

void AMGamePlayerController::ToggleInventoryWidget()
{
	bIsInventoryShown = !bIsInventoryShown;
	IMMovement* Movement = FMHelperFunctions::GetComponentByInterface<IMMovement>(GetPawn());
	check(Movement);
	bIsInventoryShown ? Movement->ResetCanMove() : Movement->SetCanMove();
	UpdateInputMode();
	OnToggleInventoryWidgetEvent.Broadcast();
}

FOnTogglewWidget& AMGamePlayerController::OnToggleInventoryWidget()
{
	return OnToggleInventoryWidgetEvent;
}

FOnTogglewWidget& AMGamePlayerController::OnTogglePauseWidget()
{
	return OnTogglePauseWidgetEvent;
}
