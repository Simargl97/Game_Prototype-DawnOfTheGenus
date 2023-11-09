// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "MInteractWidgetComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMInteractWidgetComponent final: public UWidgetComponent
{
	GENERATED_BODY()
	
public:
	UMInteractWidgetComponent();
	virtual void BeginPlay() override;
	void SetObjectName(const FText& InObjectName);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FText ObjectName;

	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FText InteractText;

	void UpdateWidgetObjectData() const;
};
