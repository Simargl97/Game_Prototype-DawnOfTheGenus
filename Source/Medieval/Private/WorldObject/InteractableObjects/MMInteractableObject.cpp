// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/InteractableObjects/MMInteractableObject.h"
#include "Core/Components/MInteractWidgetComponent.h"

	AMMInteractableObject::AMMInteractableObject() : Super ()
{
		StaticMeshComponent = CreateOptionalDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
		SetRootComponent(StaticMeshComponent);

		InteractWidgetComponent = CreateDefaultSubobject <UMInteractWidgetComponent>(TEXT("InteractWidgetComponent"));
		check(InteractWidgetComponent);
		InteractWidgetComponent->SetupAttachment(StaticMeshComponent);
}

	void AMMInteractableObject::Interact(AActor* OtherActor)
	{
		if (CanInteract())
		{
			DoInteract(OtherActor);
		}
	}

	void AMMInteractableObject::BeginPlay()
	{
		Super::BeginPlay();
		check(InteractWidgetComponent);
		InteractWidgetComponent->SetObjectName(GetObjectName());
	}

	FText AMMInteractableObject::GetObjectName() const
	{
		return FText();
	}

	void AMMInteractableObject::DoInteract(AActor* OtherActor)
	{

	}

	bool AMMInteractableObject::CanInteract() const
	{
		return true;
	}

	void AMMInteractableObject::OnEnter()
	{
		if (CanInteract())
		{
			check(InteractWidgetComponent);
			InteractWidgetComponent->SetVisibility(true);
		}
	}

	void AMMInteractableObject::OnLeave()
	{
		if (CanInteract())
		{
			check(InteractWidgetComponent);
			InteractWidgetComponent->SetVisibility(false);
		}
	}