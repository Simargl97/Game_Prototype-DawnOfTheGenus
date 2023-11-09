// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "UI/Base/MMButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"

FOnButtonClickedEvent& UMMButton::OnClicked() const
{
	check(Button);
	return Button->OnClicked;
}

void UMMButton::NativePreConstruct()
{
	Super::NativePreConstruct();
	if (TextBlock)
	{
		TextBlock->SetText(TextButton);
	}
}
