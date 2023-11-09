// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "DayNightSystem/MDayNightSystem.h"
#include "Engine/DirectionalLight.h"
#include "DayNightSystem/MMoon.h"

void AMDayNightSystem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	Time = (Day - 1) * SecondsInDay + Hour * SecondsInHour + Minute * SecondsInMinute + Second;
	UpdateAll();
}

void AMDayNightSystem::UpdateAll() const
{
	UpdateDirectionalLight();
	UpdateMoon();
}

void AMDayNightSystem::UpdateDirectionalLight() const
{
	if (DirectionalLight && DirectionalLightPitchCurve)
	{
		UpdateRotation(DirectionalLight, DirectionalLightPitchCurve);
	}
}

void AMDayNightSystem::UpdateRotation(AActor* Actor, const UCurveFloat* Curve) const
{
	check(Actor);
	check(Curve);

	const float PitchInRadians = FMath::DegreesToRadians(Curve->GetFloatValue(GetHour()));
	const FQuat DirectionalLightRotation = FQuat(FVector::RightVector, PitchInRadians);
	Actor->SetActorRotation(DirectionalLightRotation);
}

float AMDayNightSystem::GetHour() const
{
	return static_cast<float>(FMath::RoundToInt32(Time) % SecondsInDay) / SecondsInHour;
}

void AMDayNightSystem::UpdateMoon() const
{
	if (Moon && MoonPitchCurve && MoonPhaseCurve)
	{
		UpdateRotation(Moon, MoonPitchCurve);
		Moon->SetPhase(MoonPhaseCurve->GetFloatValue(FMath::RoundToInt32(GetDay()) % 28));
	}
}

float AMDayNightSystem::GetDay() const
{
	return Time / SecondsInDay + 1;
}

void AMDayNightSystem::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::IncreaseTime, GetTimerRate(), true);
}

void AMDayNightSystem::IncreaseTime()
{
	Time += TimeSpeed * GetTimerRate();
	UpdateAll();
}

float AMDayNightSystem::GetTimerRate() const
{
	check(TimeSpeed > 0);
	return FMath::Max(1 / TimeSpeed, MinTimerRate);
}