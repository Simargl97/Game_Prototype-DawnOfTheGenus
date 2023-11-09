// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/MItemRowName.h"
#include "WorldObject/MWorldObject.h"
#include "MWeapon.generated.h"

class USkeletalMeshComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMWeapon : public AMWorldObject, public IMItemRowName
{
	GENERATED_BODY()
	
public:
	AMWeapon();
	virtual void SetRowName(const FName& InRowName) override;
	virtual FName GetRowName() const override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Settings")
	USkeletalMeshComponent* SkeletalMeshComponent;

private:
	FName RowName;
};
