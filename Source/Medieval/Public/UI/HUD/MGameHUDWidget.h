// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/HUD/MHUDWidget.h"
#include "MGameHUDWidget.generated.h"

class UMInventoryWidget;
class UMInventoryMessagesWidget;
class UMPlayerInventoryStrategy;
class UMPauseWidget;

UCLASS(Abstract)
class MEDIEVAL_API UMGameHUDWidget final: public UMHUDWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UMInventoryWidget* PlayerInventoryWidget;

	UPROPERTY(meta = (BindWidget))
	UMInventoryMessagesWidget* InventoryMessagesWidget;

	UPROPERTY(meta = (BindWidget))
	UMPauseWidget* PauseWidget;

	virtual void NativeConstruct() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<UMPlayerInventoryStrategy> PlayerInventoryStrategyClass;
};
