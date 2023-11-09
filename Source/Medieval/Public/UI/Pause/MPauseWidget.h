// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MPauseWidget.generated.h"

class UMMButton;

UCLASS(Abstract)
class MEDIEVAL_API UMPauseWidget : public UMUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UMMButton* ContinueButton;

	UPROPERTY(meta = (BindWidget))
	UMMButton* ReturnToMainMenuButton;

	UPROPERTY(meta = (BindWidget))
	UMMButton* QuitGameButton;

	virtual void NativeConstruct() override;

private:
	UFUNCTION()
	void ContinueGameClicked();

	UFUNCTION()
	void ReturnToMainMenuClicked();

	UFUNCTION()
	void QuitGameClicked();
};
