// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/Interfaces/MMovement.h"
#include "MPawnAnimInstance.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API UMPawnAnimInstance final: public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Speed = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	float Direction = 0.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	bool bIsFalling = false;

private:
	UPROPERTY()
	APawn* Pawn;

	IMMovement* Movement;
};
