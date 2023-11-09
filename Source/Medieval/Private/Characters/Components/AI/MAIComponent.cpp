// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/AI/MAIComponent.h"
#include "AIController.h"
#include "NavigationSystem.h"
#include "Characters/Interfaces/MMovement.h"
#include "Core/Helpers/MHelperFunctions.h"

void UMAIComponent::Start(AAIController* InAIController)
{
	AIController = InAIController;
}

void UMAIComponent::Stop()
{
	check(AIController);
	AIController->StopMovement();
}

void UMAIComponent::OnMoveCompleted(const bool bIsSuccess)
{
}

void UMAIComponent::SetMovementType(const EMMovementType& MovementType) const
{
	IMMovement* Movement = FMHelperFunctions::GetComponentByInterface<IMMovement>(GetControlledPawn());
	check(Movement);
	Movement->SetMovementType(MovementType);
}

void UMAIComponent::MoveToLocation(const FVector& Location) const
{
	check(AIController);
	AIController->MoveToLocation(Location);
}

AActor* UMAIComponent::GetControlledPawn() const
{
	check(AIController);
	return AIController->GetPawn();
}

FVector UMAIComponent::GetRandomPointInNavigableRadius(const FVector& Origin, const float Radius, const FColor& DebugColor) const
{
	const UNavigationSystemV1* NavSys = UNavigationSystemV1::GetCurrent(GetWorld());
	check(NavSys);
	FNavLocation ResultLocation;
	NavSys->GetRandomPointInNavigableRadius(Origin, Radius, ResultLocation);

	DrawDebugSphere(GetWorld(), ResultLocation.Location, 100, 10, DebugColor, false, 10.0f);

	return ResultLocation.Location;
}