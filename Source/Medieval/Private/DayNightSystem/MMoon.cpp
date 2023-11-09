// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "DayNightSystem/MMoon.h"

AMMoon::AMMoon() : Super()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	check(StaticMeshComponent);
	StaticMeshComponent->SetupAttachment(SceneComponent);
}

void AMMoon::SetPhase(const float Phase) const
{
	check(Phase <= 1.0f);
	check(Phase >= -1.0f);
	check(StaticMeshComponent);
	StaticMeshComponent->SetScalarParameterValueOnMaterials(PhaseParameterName, Phase);
}
