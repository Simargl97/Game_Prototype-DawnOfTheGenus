// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/HUD/MGameHUDWidget.h"
#include "Characters/Interfaces/MHUDPlayerController.h"
#include "Core/Interfaces/MInventory.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "UI/Inventory/MInventoryWidget.h"
#include "UI/Inventory/MInventoryMessagesWidget.h"
#include "UI/Inventory/Strategies/MPlayerInventoryStrategy.h"
#include "UI/Pause/MPauseWidget.h"

void UMGameHUDWidget::NativeConstruct()
{
	Super::NativeConstruct();
	check(PlayerInventoryWidget);
	check(InventoryMessagesWidget);
	check(PlayerInventoryStrategyClass);
	check(PauseWidget);

	IMInventory* PlayerInventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(GetOwningPlayerPawn());
	check(PlayerInventory);
	PlayerInventoryWidget->SetInventory(PlayerInventory);
	
	UMPlayerInventoryStrategy* PlayerInventoryStrategy = NewObject<UMPlayerInventoryStrategy>(this, PlayerInventoryStrategyClass);
	PlayerInventoryWidget->SetStrategy(PlayerInventoryStrategy);
	PlayerInventoryStrategy->SetPlayer(GetOwningPlayerPawn());

	PlayerInventoryWidget->Hide();
	InventoryMessagesWidget->SetInventory(PlayerInventory);

	IMHUDPlayerController* HUDPlayerController = Cast<IMHUDPlayerController>(GetOwningPlayer());
	check(HUDPlayerController);
	HUDPlayerController->OnToggleInventoryWidget().AddUObject(PlayerInventoryWidget, &ThisClass::Toggle);
	HUDPlayerController->OnTogglePauseWidget().AddUObject(PauseWidget, &ThisClass::Toggle);

	PauseWidget->Hide();
}