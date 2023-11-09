// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "MAIComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnEscaped);

enum class EMMovementType : uint8;
class AAIController;

UCLASS(Abstract)
class MEDIEVAL_API UMAIComponent : public UMActorComponent
{
	GENERATED_BODY()
	
public:
	FOnEscaped OnEscaped;

	virtual void Start(AAIController* InAIController);
	virtual void Stop();
	virtual void OnMoveCompleted(const bool bIsSuccess);

protected:
	void SetMovementType(const EMMovementType& MovementType) const;
	void MoveToLocation(const FVector& Location) const;
	AActor* GetControlledPawn() const;
	FVector GetRandomPointInNavigableRadius(const FVector& Origin, const float Radius, const FColor& DebugColor) const;

private:
	UPROPERTY()
	AAIController* AIController;
};
