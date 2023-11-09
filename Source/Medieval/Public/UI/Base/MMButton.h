// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MMButton.generated.h"

class FOnButtonClickedEvent;
class UButton;
class UTextBlock;

UCLASS(Abstract)
class MEDIEVAL_API UMMButton final: public UMUserWidget
{
	GENERATED_BODY()

public:
	FOnButtonClickedEvent& OnClicked() const;

protected:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FText TextButton;

	UPROPERTY(meta = (BindWidget))
	UButton* Button;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* TextBlock;

	virtual void NativePreConstruct() override;

};
