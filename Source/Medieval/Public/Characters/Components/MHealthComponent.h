// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "MHealthComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnDead);

UCLASS()
class MEDIEVAL_API UMHealthComponent final: public UMActorComponent
{
	GENERATED_BODY()
	
public:
	FOnDead OnDead;

	virtual void BeginPlay() override;
	void AddHealth(const float Add);
	void ReduceHealth(const float Reduce);
	void SetCurrentHealth(const float InCurrentHealth);
	bool IsDead();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0"));
	float MaxHealth = 100.0f;

	float CurrentHealth = MaxHealth;
	bool bIsDead = false;

};
