// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/Interfaces/MInteract.h"
#include "WorldObject/MWorldObject.h"
#include "MMInteractableObject.generated.h"

class UMInteractWidgetComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMMInteractableObject : public AMWorldObject, public IMInteract
{
	GENERATED_BODY()
	
public:
	AMMInteractableObject();
	virtual void Interact(AActor* OtherActor) override final;
	virtual void OnEnter() override;
	virtual void OnLeave() override;
protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;


	UPROPERTY(VisibleAnywhere, Category = "Components")
	UMInteractWidgetComponent* InteractWidgetComponent;

	virtual void BeginPlay() override;
	virtual FText GetObjectName() const;
	virtual void DoInteract(AActor* OtherActor);
	virtual bool CanInteract() const;
};
