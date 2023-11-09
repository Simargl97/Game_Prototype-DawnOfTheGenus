// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include <Kismet/KismetSystemLibrary.h>
#include "Core/BaseTypes/MActorComponent.h"
#include "MInteractComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEntered, AActor*);
DECLARE_MULTICAST_DELEGATE_OneParam(FOnLeft, AActor*);

UCLASS()
class MEDIEVAL_API UMInteractComponent final: public UMActorComponent
{
	GENERATED_BODY()
	
public:
	FOnEntered OnEntered;
	FOnLeft OnLeft;

	void Start(USceneComponent* InSceneComponent);
	AActor* GetInteractingActor() const;

private:
	FTimerHandle TimerHandle;

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
	float TimerTickRate = 0.1f;

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float Radius = 40.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float Distance = 200.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TEnumAsByte<ETraceTypeQuery> TraceTypeQuery;

	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TEnumAsByte<EDrawDebugTrace::Type> DrawDebugType;
	
	UPROPERTY()
	USceneComponent* SceneComponent;

	UPROPERTY()
	AActor* InteractingActor;

	void InteractTick();
};
