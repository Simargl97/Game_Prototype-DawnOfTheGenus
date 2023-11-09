// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Interact/MInteractWidget.h"
#include "Components/TextBlock.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "Core/Settings/MGameSettings.h"

void UMInteractWidget::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (InteractKeyTextBlock)
	{
		const UMGameSettings* GameSettings = GetDefault<UMGameSettings>();
		check(GameSettings);
		const UInputMappingContext* InputMappingContext = GameSettings->InputMappingContext.LoadSynchronous();
		InteractKeyTextBlock->SetText(FMHelperFunctions::GetDisplayNameByAction(InputMappingContext, InteractAction));
	}
}

void UMInteractWidget::SetObjectName(const FText& ObjectName) const
{
	check(ObjectNameTextBlock);
	ObjectNameTextBlock->SetText(ObjectName);
}

void UMInteractWidget::SetInteractText(const FText& InteractText) const
{
	check(InteractTextTextBlock);
	InteractTextTextBlock->SetText(InteractText);
}