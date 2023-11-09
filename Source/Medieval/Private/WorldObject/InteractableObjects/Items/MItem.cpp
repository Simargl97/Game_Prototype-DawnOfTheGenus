// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "WorldObject/InteractableObjects/Items/MItem.h"
#include "Core/Helpers/MItemHelper.h"
#include "Core/Helpers/MHelperFunctions.h"
#include "Core/Interfaces/MInventory.h"

void AMItem::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	ItemRow.DataTable = FMItemHelper::GetDataTable();
	InitMesh();

}

void AMItem::SetRowName(const FName& InRowName)
{
	ItemRow.RowName = InRowName;
	InitMesh();
}

FName AMItem::GetRowName() const
{
	return ItemRow.RowName;
}

void AMItem::InitMesh()
{
	if (!ItemRow.RowName.IsNone())
	{
		check(StaticMeshComponent);
		StaticMeshComponent->SetStaticMesh(FMItemHelper::GetItemStaticMesh(ItemRow.RowName));
	}
}


FText AMItem::GetObjectName() const
{
	return FMItemHelper::GetItemName(ItemRow.RowName);
}

void AMItem::DoInteract(AActor* OtherActor)
{
	Super::DoInteract(OtherActor);
	IMInventory* Inventory = FMHelperFunctions::GetComponentByInterface<IMInventory>(OtherActor);
	if (Inventory)
	{
		Inventory->AddItem(ItemRow.RowName);
		Destroy();
	}
}