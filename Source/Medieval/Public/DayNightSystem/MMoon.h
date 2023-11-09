// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MMoon.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API AMMoon final: public AActor
{
	GENERATED_BODY()
	
public:	
	AMMoon();
	void SetPhase(const float Phase) const;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	USceneComponent* SceneComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	FName PhaseParameterName;
};
