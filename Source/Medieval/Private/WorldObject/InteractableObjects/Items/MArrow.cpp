// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/InteractableObjects/Items/MArrow.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Core/Interfaces/MAddingArrow.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DamageEvents.h"

AMArrow::AMArrow() : Super()
{
	SetActorEnableCollision(false);

	ProjectileMovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
	check(ProjectileMovementComponent);
	ProjectileMovementComponent->SetAutoActivate(false);
	ProjectileMovementComponent->bRotationFollowsVelocity = true;
}

void AMArrow::Fire(const float Charge)
{
	check(StaticMeshComponent);
	check(ProjectileMovementComponent);

	SetActorEnableCollision(true);
	StaticMeshComponent->SetNotifyRigidBodyCollision(true);

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &ThisClass::OnHit);
	ProjectileMovementComponent->Velocity = GetActorForwardVector() * FMath::Lerp(MinSpeed, MaxSpeed, Charge);
	ProjectileMovementComponent->Activate();
}

void AMArrow::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	check(OtherActor);
	check(StaticMeshComponent);
	check(ProjectileMovementComponent);

	ProjectileMovementComponent->Deactivate();
	UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
	StaticMeshComponent->SetNotifyRigidBodyCollision(false);

	FPointDamageEvent PointDamageEvent;
	PointDamageEvent.HitInfo = Hit;

	OtherActor->TakeDamage(DamageAmount, PointDamageEvent, nullptr, GetOwner());
	AttachToComponent(OtherComp, FAttachmentTransformRules(EAttachmentRule::KeepWorld, true), Hit.BoneName);

	if (IMAddingArrow* AddingArrow = Cast<IMAddingArrow>(OtherActor))
	{
		AddingArrow->AddArrow(this);
	}
}

void AMArrow::SetDamageAmount(const float InDamageAmount)
{
	check(InDamageAmount >= 0);
	DamageAmount = InDamageAmount;
}

bool AMArrow::CanInteract() const
{
	check(ProjectileMovementComponent);
	return !ProjectileMovementComponent->IsActive();
}
