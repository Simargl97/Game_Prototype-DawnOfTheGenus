// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/MUserWidget.h"
#include "Kismet/GameplayStatics.h"

void UMUserWidget::Show()
{
	if (IsVisible()) return;
	SetVisibility(ESlateVisibility::Visible);
}

void UMUserWidget::Hide()
{
	if (!IsVisible()) return;
	if (HideAnimation)
	{
		StopAllAnimations();
		OnAnimationFinishedEvent.BindDynamic(this, &ThisClass::HideAnimationFinished);
		BindToAnimationFinished(HideAnimation, OnAnimationFinishedEvent);
		PlayAnimation(HideAnimation);
	}
	else
	{
		HideAnimationFinished();
	}
}

void UMUserWidget::HideAnimationFinished()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void UMUserWidget::Toggle()
{
	IsVisible() ? Hide() : Show();
}

FTimerManager& UMUserWidget::GetWorldTimerManager() const
{
	check(GetWorld());
	return GetWorld()->GetTimerManager();
}

void UMUserWidget::Update(){}

IMGameState* UMUserWidget::GetGameState() const
{
	return Cast<IMGameState>(UGameplayStatics::GetGameInstance(this));
}
