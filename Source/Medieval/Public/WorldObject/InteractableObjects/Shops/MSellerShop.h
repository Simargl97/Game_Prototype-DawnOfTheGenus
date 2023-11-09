// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "WorldObject/InteractableObjects/Shops/MShop.h"
#include "MSellerShop.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API AMSellerShop final: public AMShop
{
	GENERATED_BODY()
	
protected:
	virtual void DoInteract(AActor* OtherActor) override;

private:
	float GetNeedCoins() const;
};
