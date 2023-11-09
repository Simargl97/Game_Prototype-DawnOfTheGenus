// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Characters/Interfaces/MStamina.h"
#include "UI/Stats/MStaminaWidget.h"
#include "Core/BaseTypes/MActorComponent.h"
#include "MStaminaComponent.generated.h"

UCLASS()
class MEDIEVAL_API UMStaminaComponent final: public UMActorComponent, public IMStamina 
{
	GENERATED_BODY()
	
public:
	UMStaminaComponent();
	virtual void BeginPlay() override;
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	virtual void UseStamina(const float UsedStamina) override;
	virtual float GetCurrentStamina() const override;
	virtual float GetPercentStamina() const override;
	virtual FOnChangedStamina& OnChangedStamina() override;
	virtual FOnRanOutStamina& OnRanOutStamina() override;

protected:
	virtual void SetCurrentStamina(const float InCurrentStamina);

	UPROPERTY(BlueprintReadWrite, Category = "Setting")
	float CurrentStamina = MaxStamina;
private:

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0"))
	float MaxStamina = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Setting", meta = (ClampMin = "0", UIMin = "0"))
	float RecoveryPerSecond = 10.0f;

	FOnChangedStamina OnChangedStaminaEvent;
	FOnRanOutStamina OnRanOutStaminaEvent;
};
