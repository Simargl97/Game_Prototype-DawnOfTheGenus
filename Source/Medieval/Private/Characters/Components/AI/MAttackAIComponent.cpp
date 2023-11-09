// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/AI/MAttackAIComponent.h"
#include "NavigationSystem.h"
#include "Characters/Interfaces/MMovement.h"

void UMAttackAIComponent::Start(AAIController* InAIController)
{
	Super::Start(InAIController);
	SetMovementType(EMMovementType::Sprinting);
	GetWorldTimerManager().SetTimer(TimerHandleAttack, this, &ThisClass::GoToEnemy, TimerRate, true, 0.0f);
}

void UMAttackAIComponent::GoToEnemy()
{
	check(GetControlledPawn());
	if (GetControlledPawn()->GetDistanceTo(Enemy) < GetCurrentAttackDistance())
	{
		MoveToLocation(GetEnemy());
	}
	else
	{
		bDamageHasBeenReceived = false;
		OnEscaped.Broadcast();
	}
}

float UMAttackAIComponent::GetCurrentAttackDistance() const
{
	return bDamageHasBeenReceived ? AttackDistanceHit : AttackDistance;
}

FVector UMAttackAIComponent::GetEnemy() const
{
	check(Enemy);
	return Enemy->GetActorLocation();

}

void UMAttackAIComponent::Stop()
{
	Super::Stop();
	GetWorldTimerManager().ClearTimer(TimerHandleAttack);
}

void UMAttackAIComponent::SetEnemy(const AActor* InEnemy)
{
	Enemy = InEnemy;
}

void UMAttackAIComponent::DamageHasBeenReceived()
{
	bDamageHasBeenReceived = true;
}