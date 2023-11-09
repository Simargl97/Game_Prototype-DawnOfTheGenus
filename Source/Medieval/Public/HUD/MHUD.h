// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MHUD.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API AMHUD final: public AHUD
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	TSubclassOf<UUserWidget> HUDWidgetClass;
};
