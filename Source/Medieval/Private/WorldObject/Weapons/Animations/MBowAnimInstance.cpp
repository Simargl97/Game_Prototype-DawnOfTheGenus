// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/Weapons/Animations/MBowAnimInstance.h"
#include "Characters/Interfaces/MBowFighting.h"

void UMBowAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	BowFighting = Cast<IMBowFighting>(GetOwningActor());
}

void UMBowAnimInstance::NativeUpdateAnimation(const float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (BowFighting)
	{
		Charge = BowFighting->GetCharge();
	}
}
