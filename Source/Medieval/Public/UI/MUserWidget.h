// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MUserWidget.generated.h"

class IMGameState;

UCLASS(Abstract)
class MEDIEVAL_API UMUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void Show();
	void Hide();
	void Toggle();

protected:
	UPROPERTY(Transient, meta = (BindWidgetAnimOptional))
	UWidgetAnimation* HideAnimation;

	virtual void Update();
	IMGameState* GetGameState() const;
	FTimerManager& GetWorldTimerManager() const;

private:
	FWidgetAnimationDynamicEvent OnAnimationFinishedEvent;

	UFUNCTION()
	void HideAnimationFinished();
};
