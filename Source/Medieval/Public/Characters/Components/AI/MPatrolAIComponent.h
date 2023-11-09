// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Components/AI/MAIComponent.h"
#include "MPatrolAIComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMPatrolAIComponent final : public UMAIComponent
{
	GENERATED_BODY()
	
public:
	virtual void Start(AAIController* InAIController) override;
	virtual void Stop() override;
	virtual void OnMoveCompleted(const bool bIsSuccess) override;
	void SetStartLocation(const FVector& InStartLocation);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float Radius = 2000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
	float DelayAfterSuccess = 2.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0.2", UIMin = "0.2", Units = "Seconds"))
	float DelayAfterFail = 0.2f;

	FTimerHandle TimerHandle;
	FVector StartLocation;

	void GoToNextLocation() const;
};
