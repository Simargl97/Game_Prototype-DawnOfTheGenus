// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Spawner/MSpawner.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"

AMSpawner::AMSpawner()
{
	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	check(BoxComponent);
	SetRootComponent(BoxComponent);
	BoxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

void AMSpawner::BeginPlay()
{
	Super::BeginPlay();
	for (uint32 i = 0; i < Count; ++i)
	{
		Spawn();
	}
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::Check, CheckRate, true);
	
}

void AMSpawner::Spawn()
{
	check(GetWorld());
	AActor* Actor = GetWorld()->SpawnActor<AActor>(ActorClass, GetSpawnLocation(), FRotator::ZeroRotator);
	if (Actor)
	{
		Actors.Add(Actor);
	}
	else
	{
		Spawn();
	}
}

FVector AMSpawner::GetSpawnLocation() const
{
	check(BoxComponent);
	const FTransform BoxComponentTransform = {BoxComponent->GetComponentRotation(), BoxComponent->GetComponentLocation(), FVector::OneVector};
	const FVector RandomPoint = UKismetMathLibrary::RandomPointInBoundingBox(FVector::ZeroVector, BoxComponent->GetScaledBoxExtent());

	return UKismetMathLibrary::TransformLocation(BoxComponentTransform, RandomPoint);
}

void AMSpawner::Check()
{
	const uint32 CountActors = Actors.Num();
	for (uint32 i = 0; i < CountActors; ++i)
	{
		if (!IsValid(Actors[i]))
		{
			Actors.RemoveAt(i);
			Spawn();
		}
	}
}