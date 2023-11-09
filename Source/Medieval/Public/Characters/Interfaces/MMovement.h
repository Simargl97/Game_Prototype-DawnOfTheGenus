// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MMovement.generated.h"

class IMStamina;

UENUM(BlueprintType)
enum class EMMovementType : uint8
{
	Walking = 0,
	Running,
	Sprinting
};

UINTERFACE(MinimalAPI)
class UMMovement : public UInterface
{
	GENERATED_BODY()
};

class MEDIEVAL_API IMMovement
{
	GENERATED_BODY()

	
public:
	virtual bool IsInAir() const = 0;
	virtual void SetStamina(IMStamina* Stamina) = 0;
	virtual void SetMovementType(const EMMovementType& InMovementType) = 0;
	virtual void SetCanMove() = 0;
	virtual void ResetCanMove() = 0;
	virtual bool CanMove() const = 0;
};
