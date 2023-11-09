// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/AI/MEscapeAIComponent.h"
#include "NavigationSystem.h"
#include "Characters/Interfaces/MMovement.h"

void UMEscapeAIComponent::Start(AAIController* InAIController)
{
	Super::Start(InAIController);
	SetMovementType(EMMovementType::Sprinting);
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::GoToNextLocation, TimerRate, true, 0.0f);
}

void UMEscapeAIComponent::GoToNextLocation()
{
	check(GetControlledPawn());
	if (GetControlledPawn()->GetDistanceTo(Enemy) < GetCurrentSafeDistance())
	{
		MoveToLocation(GetNextLocation());
	}
	else
	{
		bDamageHasBeenReceived = false;
		OnEscaped.Broadcast();
	}
}

float UMEscapeAIComponent::GetCurrentSafeDistance() const
{
	return bDamageHasBeenReceived ? SafeDistanceAfterHit : SafeDistance;
}

FVector UMEscapeAIComponent::GetNextLocation() const
{
	check(Enemy);
	check(GetControlledPawn());

	FVector Delta = GetControlledPawn()->GetActorLocation() - Enemy->GetActorLocation();
	Delta.Normalize();
	const FVector Origin = GetControlledPawn()->GetActorLocation() + Delta * DistanceForEscape;

	return GetRandomPointInNavigableRadius(Origin, Radius, FColor::Green);
}

void UMEscapeAIComponent::Stop()
{
	Super::Stop();
	GetWorldTimerManager().ClearTimer(TimerHandle);
}

void UMEscapeAIComponent::SetEnemy(const AActor* InEnemy)
{
	Enemy = InEnemy;
}

void UMEscapeAIComponent::DamageHasBeenReceived()
{
	bDamageHasBeenReceived = true;
}