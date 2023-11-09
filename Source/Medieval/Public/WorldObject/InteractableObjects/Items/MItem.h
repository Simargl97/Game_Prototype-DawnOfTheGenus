// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Core/Interfaces/MItemRowName.h"
#include "WorldObject/InteractableObjects/MMInteractableObject.h"
#include "MItem.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API AMItem : public AMMInteractableObject, public IMItemRowName
{
	GENERATED_BODY()
	
public:
	virtual void OnConstruction(const FTransform& Transform) override;
	virtual void SetRowName(const FName& InRowName) override;
	virtual FName GetRowName() const override;

protected:
	virtual FText GetObjectName() const;
	virtual void DoInteract(AActor* OtherActor) override;

private:
	UPROPERTY(EditAnywhere, Category = "Settings")
	FDataTableRowHandle ItemRow;

	void InitMesh();
};
