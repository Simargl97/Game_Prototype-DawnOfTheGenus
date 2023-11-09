// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/Components/MInteractWidgetComponent.h"
#include "Core/Interfaces/MInteractData.h"

UMInteractWidgetComponent::UMInteractWidgetComponent() : Super()
{
	SetWidgetSpace(EWidgetSpace::Screen);
	SetDrawAtDesiredSize(true);
	SetVisibility(false);
}

void UMInteractWidgetComponent::BeginPlay()
{
	Super::BeginPlay();
	UpdateWidgetObjectData();
}

void UMInteractWidgetComponent::UpdateWidgetObjectData() const
{
	const IMInteractData* InteractData = Cast<IMInteractData>(GetWidget());
	check(InteractData);
	InteractData->SetObjectName(ObjectName);
	InteractData->SetInteractText(InteractText);
}

void UMInteractWidgetComponent::SetObjectName(const FText& InObjectName)
{
	ObjectName = InObjectName;
	UpdateWidgetObjectData();
}