// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MBowAnimInstance.generated.h"

class IMBowFighting;

UCLASS(Abstract)
class MEDIEVAL_API UMBowAnimInstance final: public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(const float DeltaSeconds) override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintreadOnly)
	float Charge = 0.0f;

private:
	IMBowFighting* BowFighting;
};
