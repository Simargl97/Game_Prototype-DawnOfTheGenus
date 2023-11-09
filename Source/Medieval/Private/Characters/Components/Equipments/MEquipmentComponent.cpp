// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Components/Equipments/MEquipmentComponent.h"
#include "Core/Interfaces/MItemRowName.h"

void UMEquipmentComponent::ToggleEquip(const FName& RowName)
{
	const bool bIsNeedEquip = !RowName.IsEqual(EquippedItemRowName);
	UnEquip();
	if (bIsNeedEquip)
	{
		Equip(RowName);
	}
}

void UMEquipmentComponent::UnEquip()
{
	if (EquippedActor)
	{
		EquippedActor->Destroy();
	}
	EquippedItemRowName = NAME_None;
}

void UMEquipmentComponent::Equip(const FName& RowName)
{
	check(GetWorld());
	EquippedActor = GetWorld()->SpawnActorDeferred<AActor>(EquippedActorClass, FTransform::Identity, GetOwner(), nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

	if (EquippedActor)
	{
		EquippedActor->FinishSpawning(FTransform::Identity);
		AttachActorToSceneComponent();
		IMItemRowName* ItemRowName = Cast<IMItemRowName>(EquippedActor);
		check(ItemRowName);
		ItemRowName->SetRowName(RowName);
		EquippedItemRowName = RowName;
	}
}

void UMEquipmentComponent::AttachActorToSceneComponent(USceneComponent* InEquippedSceneComponent) const
{
	if (EquippedActor)
	{
		const FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules::SnapToTargetNotIncludingScale;
		EquippedActor->AttachToComponent(InEquippedSceneComponent? InEquippedSceneComponent : EquippedSceneComponent, AttachmentRules);
	}
}

FName UMEquipmentComponent::GetEquippedItemRowName() const
{
	return EquippedItemRowName;
}

void UMEquipmentComponent::SetEquippedSceneComponent(USceneComponent* InEquippedSceneComponent)
{
	EquippedSceneComponent = InEquippedSceneComponent;
}

bool UMEquipmentComponent::IsEquipped() const
{
	return !EquippedItemRowName.IsNone();
}

AActor* UMEquipmentComponent::GetEquippedActor() const
{
	return EquippedActor;
}