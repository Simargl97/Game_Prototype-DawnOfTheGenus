// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Core/BaseTypes/MActorComponent.h"

FTimerManager& UMActorComponent::GetWorldTimerManager() const
{
    check(GetWorld());
    return GetWorld()->GetTimerManager();
}
