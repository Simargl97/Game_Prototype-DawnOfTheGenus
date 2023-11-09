// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MHUDWidget.generated.h"

class UMLoadingScreenWidget;

UCLASS(Abstract)
class MEDIEVAL_API UMHUDWidget : public UMUserWidget
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(meta = (BindWidget))
	UMLoadingScreenWidget* LoadingScreenWidget;

	virtual void NativeConstruct();
};
