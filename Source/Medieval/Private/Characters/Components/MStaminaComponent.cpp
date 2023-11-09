// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "Characters/Components/MStaminaComponent.h"

UMStaminaComponent::UMStaminaComponent() : Super()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UMStaminaComponent::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Stamina"));
}

void UMStaminaComponent::SetCurrentStamina(const float InCurrentStamina)
{
	CurrentStamina = FMath::Clamp(InCurrentStamina, 0, MaxStamina);
	OnChangedStaminaEvent.Broadcast();
	if (FMath::IsNearlyZero(CurrentStamina))
	{
		OnRanOutStaminaEvent.Broadcast();
	}
}

void UMStaminaComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	SetCurrentStamina(CurrentStamina + RecoveryPerSecond * DeltaTime);
}

void UMStaminaComponent::UseStamina(const float UsedStamina)
{
	SetCurrentStamina(CurrentStamina - UsedStamina);
}

float UMStaminaComponent::GetCurrentStamina() const
{
	return CurrentStamina;
}

float UMStaminaComponent::GetPercentStamina() const
{
	if (FMath::IsNearlyZero(MaxStamina)) return 0.0f;
	return CurrentStamina / MaxStamina;
}

FOnChangedStamina& UMStaminaComponent::OnChangedStamina()
{
	return OnChangedStaminaEvent;
}

FOnRanOutStamina& UMStaminaComponent::OnRanOutStamina()
{
	return OnRanOutStaminaEvent;
}