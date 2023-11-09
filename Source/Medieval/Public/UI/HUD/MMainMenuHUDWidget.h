// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/HUD/MHUDWidget.h"
#include "MMainMenuHUDWidget.generated.h"

class UMMButton;

UCLASS(Abstract)
class MEDIEVAL_API UMMainMenuHUDWidget final: public UMHUDWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UMMButton* NewGameButton;

	UPROPERTY(meta = (BindWidget))
	UMMButton* QuitGameButton;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void NewGameClicked();

	UFUNCTION()
	void QuitGameClicked();
};
