// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/MCharacter.h"
#include "Core/Interfaces/MInteract.h"
#include "MAnimalCharacter.generated.h"

class UBoxComponent;
class UMInteractWidgetComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMAnimalCharacter final: public AMCharacter, public IMInteract
{
	GENERATED_BODY()
	
public:
	explicit AMAnimalCharacter(const FObjectInitializer& ObjInit);
	virtual void Interact(AActor* OtherActor) override final;
	virtual void OnEnter() override;
	virtual void OnLeave() override;


protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* BlockCollision;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UMInteractWidgetComponent* InteractWidgetComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAudioComponent* AudioComponent;
	
	virtual void Dead() override;
};
