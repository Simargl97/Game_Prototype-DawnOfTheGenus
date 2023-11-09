// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/Helpers/MHelperFunctions.h"
#include "GameFramework/InputSettings.h"
#include "EnhancedActionKeyMapping.h"
#include "InputMappingContext.h"

FText FMHelperFunctions::GetDisplayNameByAction(const UInputMappingContext* InputMappingContext, const UInputAction* Action)
{
    check(InputMappingContext);
    const TArray<FEnhancedActionKeyMapping>& Mappings = InputMappingContext->GetMappings();
    for (const FEnhancedActionKeyMapping& Mapping : Mappings)
    {
        if (Mapping.Action == Action)
        {
            return Mapping.Key.GetDisplayName();
        }
    }
    return FText();
}
