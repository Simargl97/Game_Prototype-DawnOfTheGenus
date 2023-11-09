// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/AI/MPatrolAIComponent.h"
#include "Characters/Interfaces/MMovement.h"

void UMPatrolAIComponent::Start(AAIController* InAIController)
{
	Super::Start(InAIController);
	SetMovementType(EMMovementType::Walking);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::GoToNextLocation, DelayAfterSuccess);
}

void UMPatrolAIComponent::GoToNextLocation() const
{
	MoveToLocation(GetRandomPointInNavigableRadius(StartLocation, Radius, FColor::Red));
}

void UMPatrolAIComponent::Stop()
{
	Super::Stop();
	GetWorldTimerManager().ClearTimer(TimerHandle);
}

void UMPatrolAIComponent::OnMoveCompleted(const bool bIsSuccess)
{
	Super::OnMoveCompleted(bIsSuccess);
	const float RealDelay = bIsSuccess ? DelayAfterSuccess : DelayAfterFail;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::GoToNextLocation, RealDelay);
}

void UMPatrolAIComponent::SetStartLocation(const FVector& InStartLocation)
{
	StartLocation = InStartLocation;
}