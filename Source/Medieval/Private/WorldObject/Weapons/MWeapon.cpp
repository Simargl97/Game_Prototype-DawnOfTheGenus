// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/Weapons/MWeapon.h"
#include "Core/Helpers/MItemHelper.h"

AMWeapon::AMWeapon() : Super ()
{
	SkeletalMeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMeshComponent"));
	SetRootComponent(SkeletalMeshComponent);
	SetActorEnableCollision(false);
}

void AMWeapon::SetRowName(const FName& InRowName)
{
	check(SkeletalMeshComponent);
	RowName = InRowName;

	SkeletalMeshComponent->SetSkeletalMesh(FMItemHelper::GetItemSkeletalMesh(RowName));
	SkeletalMeshComponent->SetAnimInstanceClass(FMItemHelper::GetItemAnimInstanceMesh(RowName));
}

FName AMWeapon::GetRowName() const
{
	return RowName;
}
