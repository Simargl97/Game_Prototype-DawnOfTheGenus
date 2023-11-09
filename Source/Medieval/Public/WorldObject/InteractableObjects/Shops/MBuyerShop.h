// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "WorldObject/InteractableObjects/Shops/MShop.h"
#include "MBuyerShop.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API AMBuyerShop final: public AMShop
{
	GENERATED_BODY()
	
protected:
	virtual void DoInteract(AActor* OtherActor) override;
};
