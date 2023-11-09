// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/Border/MBorder.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"

AMBorder::AMBorder() : Super()
{
	ExternalBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("ExternalBoxComponent"));
	check(ExternalBoxComponent);
	ExternalBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnExternalBoxComponentEndOverlap);
	SetRootComponent(ExternalBoxComponent);

	InternalBoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("InternalBoxComponent"));
	check(InternalBoxComponent);
	InternalBoxComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnInternalBoxComponentEndOverlap);
	InternalBoxComponent->SetupAttachment(ExternalBoxComponent);
}

void AMBorder::OnExternalBoxComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Player)
	{
		Player->SetActorLocation(Location);
		UGameplayStatics::PlaySoundAtLocation(this, BorderCrossingSound, GetActorLocation());
	}
}

void AMBorder::OnInternalBoxComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	check(OtherActor);
	Player = OtherActor;
	Location = OtherActor->GetActorLocation();
}
