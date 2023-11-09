// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Components/AI/MAIComponent.h"
#include "MEscapeAIComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMEscapeAIComponent final: public UMAIComponent
{
	GENERATED_BODY()

public:
	virtual void Start(AAIController* InAIController);
	virtual void Stop() override;
	void DamageHasBeenReceived();
	void SetEnemy(const AActor* InEnemy);

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float DistanceForEscape = 1000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float SafeDistance = 3000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float SafeDistanceAfterHit = 10000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float Radius = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0.1", UIMin = "0.1", Units = "Seconds"))
	float TimerRate = 0.5f;

	UPROPERTY()
	const AActor* Enemy;

	FTimerHandle TimerHandle;
	bool bDamageHasBeenReceived = false;

	void GoToNextLocation();
	float GetCurrentSafeDistance() const;
	FVector GetNextLocation() const;
};
