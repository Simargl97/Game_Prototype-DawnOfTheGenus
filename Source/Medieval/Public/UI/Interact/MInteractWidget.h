// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/MInteractData.h"
#include "UI/MUserWidget.h"
#include "MInteractWidget.generated.h"

class UTextBlock;
class UInputAction;

UCLASS(Abstract)
class MEDIEVAL_API UMInteractWidget final: public UMUserWidget, public IMInteractData
{
	GENERATED_BODY()
	
public:

	virtual void SetObjectName(const FText& ObjectName) const override;
	virtual void SetInteractText(const FText& InteractText) const override;

protected:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ObjectNameTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* InteractTextTextBlock;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* InteractKeyTextBlock;

	virtual void NativePreConstruct() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	UInputAction* InteractAction;
};
