// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/Weapons/MBow.h"
#include "Components/AudioComponent.h"
#include "Components/TimelineComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "Core/Helpers/MItemHelper.h"
#include "Core/Interfaces/MInventory.h"
#include "WorldObject/InteractableObjects/Items/MArrow.h"

AMBow::AMBow() : Super ()
{
	ChargeAudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("ChargeAudioComponent"));
	check(ChargeAudioComponent);
	ChargeAudioComponent->SetupAttachment(GetRootComponent());
	ChargeAudioComponent->SetAutoActivate(false);
}

void AMBow::StartCharge()
{
	check(GetWorld());
	check(OwnerInventory);
	check(ChargeTimeline);
	check(ChargeAudioComponent);

	if (OwnerInventory->HasItem(ArrowRowName))
	{
		Arrow = GetWorld()->SpawnActor<AMArrow>(ArrowClass, FVector::ZeroVector, FRotator::ZeroRotator);
		check(Arrow);
		Arrow->SetOwner(GetOwner());
		Arrow->AttachToComponent(SkeletalMeshComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, ArrowSocketName);
		ChargeTimeline->PlayFromStart();
		ChargeAudioComponent->Play();
	}
}

void AMBow::StopCharge()
{
	check(ChargeTimeline);
	check(ChargeAudioComponent);
	if (IsValid(Arrow))
	{
		Arrow->Destroy();
	}
	ChargeTimeline->Stop();
	Charge = 0.0f;
	ChargeAudioComponent->Stop();
}

void AMBow::Fire()
{
	if (!IsValid(Arrow)) return;

	check(OwnerInventory);
	Arrow->SetDamageAmount(FMItemHelper::GetDamage(GetRowName()));
	Arrow->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
	Arrow->Fire(Charge);
	Arrow = nullptr;

	StopCharge();
	UGameplayStatics::PlaySoundAtLocation(this, FireSound, GetActorLocation());
	if (OwnerInventory->RemoveItem(ArrowRowName)) return;

	checkNoEntry();
}

float AMBow::GetCharge() const
{
	return Charge;
}

void AMBow::BeginPlay()
{
	Super::BeginPlay();
	ChargeTimeline = NewObject<UTimelineComponent>(this);
	check(ChargeTimeline);
	ChargeTimeline->SetLooping(false);

	FOnTimelineFloat ProgressChargeFunction;
	ProgressChargeFunction.BindUFunction(this, FName(TEXT("ProgressCharge")));

	ChargeTimeline->AddInterpFloat(ChargeCurve, ProgressChargeFunction);
	ChargeTimeline->RegisterComponent();

	OwnerInventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(GetOwner());
}

void AMBow::ProgressCharge(const float Value)
{
	Charge = Value;
}
