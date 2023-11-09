// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "MExperienceComponent.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnLevelUp);

UCLASS()
class MEDIEVAL_API UMExperienceComponent final: public UMActorComponent
{
	GENERATED_BODY()

public:
	FOnLevelUp LevelUp;

	virtual void BeginPlay() override;
	virtual float GetCurrentLevel() const;
	void AddExp(const float Add);
	void LevelUpPlayer(const float Level);
private:
	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0"));
	float MaxExp = 1000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0"));
	float CurrentExp = 0.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0"));
	float CurrentLevel = 0.0f;

	bool bIsLevelUp = false;

	void SetCurrentExp(const float InCurrentExp);
};
