// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MStaminaWidget.generated.h"

DECLARE_MULTICAST_DELEGATE(FPercentDelegate);

class UTextBlock;
class UProgressBar;

UCLASS(Abstract)
class MEDIEVAL_API UMStaminaWidget final: public UMUserWidget 
{
	GENERATED_BODY()
	
public:
	FPercentDelegate& InPercentDelegate();

	virtual void SetCurrentStamina(const float InCurrentStamina);

protected:
	virtual void NativeConstruct() override;
	
	UPROPERTY(meta =(BindWidget))
	UTextBlock* TextBlock;

	UPROPERTY(meta = (BindWidget))
	UProgressBar* ProgressBarStamina;

	UPROPERTY(EditDefaultsOnly, Category = "Setting|Value")
	float Percent = 1.0f;

private:
	FPercentDelegate InPercentDelegateEvent;
};
