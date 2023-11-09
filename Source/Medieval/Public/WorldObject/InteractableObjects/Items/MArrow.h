// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "WorldObject/InteractableObjects/Items/MItem.h"
#include "MArrow.generated.h"

class UProjectileMovementComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMArrow final: public AMItem
{
	GENERATED_BODY()
	
public:
	AMArrow();
	void Fire(const float Charge);
	void SetDamageAmount(const float InDamageAmount);

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UProjectileMovementComponent* ProjectileMovementComponent;
		
	virtual bool CanInteract() const override;
private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Speed", meta = (ClampMin = "0", UIMin = "0", Units = "CentimetersPerSecond"))
	float MinSpeed = 100.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Speed", meta = (ClampMin = "0", UIMin = "0", Units = "CentimetersPerSecond"))
	float MaxSpeed = 5000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Sounds")
	USoundBase* HitSound;

	float DamageAmount;

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
