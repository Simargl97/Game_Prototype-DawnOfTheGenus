// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "MCoreTypes.generated.h"

UENUM(BlueprintType)
enum class EMItemType : uint8
{
	Other = 0,
	Bow,
	Arrow,
	Money
};

USTRUCT(BlueprintType)
struct FMItemInfo : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	FText Name;

	UPROPERTY(EditDefaultsOnly)
	UTexture2D* Thumbnail = nullptr;

	UPROPERTY(EditDefaultsOnly)
	EMItemType ItemType = EMItemType::Other;

	UPROPERTY(EditDefaultsOnly)
	UStaticMesh* StaticMesh = nullptr;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMesh* SkeletalMesh = nullptr;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UAnimInstance> AnimInstanceClass;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
	float Damage = 0.0f;

	UPROPERTY(EditDefaultsOnly, meta = (ClampMin = "0", UIMin = "0"))
	float Price = 0.0f;
};