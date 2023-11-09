// Copyright (c). Medieval . Author: Sergoe Osipchuk

#include "Characters/MCharacter.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Characters/Components/MHealthComponent.h"
#include "Characters/Components/MExperienceComponent.h"
#include "Characters/Components/MCharacterMovementComponent.h"
#include "Core/Components/MinventoryComponent.h"
#include "Core/Components/MStartingItemsComponent.h"
#include <Core/Helpers/MHelperFunctions.h>

AMCharacter::AMCharacter(const FObjectInitializer& ObjInit) : Super(ObjInit.SetDefaultSubobjectClass<UMCharacterMovementComponent>(CharacterMovementComponentName))
{
	HealthComponent = CreateDefaultSubobject<UMHealthComponent>(TEXT("HealthComponent"));
	check(HealthComponent);
	HealthComponent->OnDead.AddUObject(this, &ThisClass::Dead);

	ExperienceComponent = CreateDefaultSubobject<UMExperienceComponent>(TEXT("ExperienceComponent"));
	check(ExperienceComponent);
	ExperienceComponent->LevelUp.AddUObject(this, &ThisClass::LevelUp);

	InventoryComponent = CreateDefaultSubobject<UMinventoryComponent>(TEXT("InventoryComponent"));
	StartingItemsComponent = CreateDefaultSubobject<UMStartingItemsComponent>(TEXT("StartingItemsComponent"));

	OnTakePointDamage.AddDynamic(this, &ThisClass::PointDamage);
}

void AMCharacter::LevelUp()
{
	UE_LOG(LogTemp, Warning, TEXT("AMCharacter::LevelUp"));
}

void AMCharacter::Dead()
{
	check(GetCapsuleComponent());
	check(GetMesh());

	GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	GetMesh()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	GetMesh()->SetSimulatePhysics(true);
}

void AMCharacter::PointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation,
	UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
	const UDamageType* DamageType, AActor* DamageCauser)
{
	check(HealthComponent);
	const float DamageMultipliers = BonesAndDamageMultipliersMatching.Contains(BoneName) ? BonesAndDamageMultipliersMatching[BoneName] : 1.0f;
	UE_LOG(LogTemp, Warning, TEXT("Damage: %f, %f"), Damage, DamageMultipliers);
	HealthComponent->ReduceHealth(Damage * DamageMultipliers);
}

bool AMCharacter::CanMove() const
{
	IMMovement* Movement = FMHelperFunctions::GetComponentByInterface<IMMovement>(this);
	check(Movement);
	return Movement->CanMove();
}

void AMCharacter::AddArrow(AActor* Arrow)
{
	AddedArrows.Add(Arrow);
}

TArray<AActor*>& AMCharacter::GetAddedArrows()
{
	return AddedArrows;
}