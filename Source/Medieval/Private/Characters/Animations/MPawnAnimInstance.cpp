// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Animations/MPawnAnimInstance.h"
#include "KismetAnimationLibrary.h"
#include "Core/Helpers/MHelperFunctions.h"

void UMPawnAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	Pawn = TryGetPawnOwner();
	Movement = FMHelperFunctions::GetComponentByInterface<IMMovement>(Pawn);
}

void UMPawnAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Pawn)
	{
		Speed = Pawn->GetVelocity().Size();
		Direction = UKismetAnimationLibrary::CalculateDirection(Pawn->GetVelocity(), Pawn->GetActorRotation());
		if (Movement) 
		{
			bIsFalling = Movement->IsInAir();
		}
	}
}
