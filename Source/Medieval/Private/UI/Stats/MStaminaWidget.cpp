// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Stats/MStaminaWidget.h"
#include "Characters/MPlayerCharacter.h"
#include "Components/ProgressBar.h"
#include "Characters/Components/MStaminaComponent.h"


void UMStaminaWidget::NativeConstruct()
{
	Super::NativeConstruct();
	if (ProgressBarStamina)
	{
		ProgressBarStamina->SetPercent(Percent);
		InPercentDelegateEvent.Broadcast();
	}
}

void UMStaminaWidget::SetCurrentStamina(const float InCurrentStamina)
{
	Percent = InCurrentStamina;
}

FPercentDelegate& UMStaminaWidget::InPercentDelegate()
{
	return InPercentDelegateEvent;
}