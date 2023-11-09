// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Controllers/MPlayerController.h"
#include "Characters/Interfaces/MHUDPlayerController.h"
#include "MGamePlayerController.generated.h"

class UInputAction;

UCLASS(Abstract)
class MEDIEVAL_API AMGamePlayerController final: public AMPlayerController, public IMHUDPlayerController
{
	GENERATED_BODY()
	
public:
	virtual void ContinueGame() override;
	virtual FOnTogglewWidget& OnToggleInventoryWidget() override;
	virtual FOnTogglewWidget& OnTogglePauseWidget() override;

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	UInputAction* InventoryAction;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	UInputAction* PauseAction;

	FOnTogglewWidget OnToggleInventoryWidgetEvent;
	FOnTogglewWidget OnTogglePauseWidgetEvent;
	bool bIsInventoryShown = false;
	bool bIsPauseShown = false;

	void ToggleInventoryWidget();
	void TogglePauseWidget();
	void UpdateInputMode();
};
