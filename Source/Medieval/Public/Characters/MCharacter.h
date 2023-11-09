// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/MMovement.h"
#include "Core/Interfaces/MAddingArrow.h"
#include "MCharacter.generated.h"

class UMHealthComponent;
class UMExperienceComponent;
class UMinventoryComponent;
class UMStartingItemsComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMCharacter : public ACharacter, public IMAddingArrow
{
	GENERATED_BODY()

public:
	explicit AMCharacter(const FObjectInitializer& ObjInit);
	virtual void AddArrow(AActor* Arrow) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMHealthComponent* HealthComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMExperienceComponent* ExperienceComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMinventoryComponent* InventoryComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMStartingItemsComponent* StartingItemsComponent;

	UFUNCTION()
	virtual void PointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, 
					UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, 
					const  UDamageType* DamageType, AActor* DamageCauser);

	virtual void Dead();
	bool CanMove() const;

	TArray<AActor*>& GetAddedArrows();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Damage")
	TMap<FName, float> BonesAndDamageMultipliersMatching;

	UPROPERTY()
	TArray<AActor*> AddedArrows;
	void LevelUp();
};
