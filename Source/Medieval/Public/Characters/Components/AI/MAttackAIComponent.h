// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Components/AI/MAIComponent.h"
#include "MAttackAIComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMAttackAIComponent final: public UMAIComponent
{
	GENERATED_BODY()
	
public:
	virtual void Start(AAIController* InAIController);
	virtual void Stop() override;
	void SetEnemy(const AActor* InEnemy);
	void DamageHasBeenReceived();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float AttackDistanceHit = 10000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float AttackDistance = 3000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Centimeters"))
	float DistanceForAttack = 50.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
	float TimerRate = 0.5;

	UPROPERTY()
	const AActor* Enemy;

	FTimerHandle TimerHandleAttack;
	bool bDamageHasBeenReceived = false;

	void GoToEnemy();
	float GetCurrentAttackDistance() const;
	FVector GetEnemy() const;
};
