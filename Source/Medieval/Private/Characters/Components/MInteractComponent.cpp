// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/MInteractComponent.h"

void UMInteractComponent::Start(USceneComponent* InSceneComponent)
{
	SceneComponent = InSceneComponent;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::InteractTick, TimerTickRate, true);
}

void UMInteractComponent::InteractTick()
{
	check(SceneComponent);
	const FVector StartLocation = SceneComponent->GetComponentLocation();
	const FVector EndLocation =StartLocation + SceneComponent->GetForwardVector() * Distance;

	FHitResult OutHit;
	UKismetSystemLibrary::SphereTraceSingle(this, StartLocation, EndLocation, Radius, TraceTypeQuery, false, TArray<AActor*>(), DrawDebugType, OutHit, true);

	if (OutHit.GetActor() != InteractingActor)
	{
		OnLeft.Broadcast(InteractingActor);
		InteractingActor = OutHit.GetActor();
		OnEntered.Broadcast(InteractingActor);
	}

	
}

AActor* UMInteractComponent::GetInteractingActor() const
{
	return InteractingActor;
}