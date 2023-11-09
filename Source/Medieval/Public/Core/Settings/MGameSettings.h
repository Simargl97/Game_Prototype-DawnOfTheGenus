// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/DeveloperSettings.h"
#include "MGameSettings.generated.h"

class UInputMappingContext;

UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = " Game Settings"))
class MEDIEVAL_API UMGameSettings : public UDeveloperSettings
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Config, EditDefaultsOnly, Category = "DataTable")
	TSoftObjectPtr<UDataTable> ItemsDataTable;

	UPROPERTY(Config, EditDefaultsOnly, Category = "Input")
	TSoftObjectPtr<UInputMappingContext> InputMappingContext;
};
