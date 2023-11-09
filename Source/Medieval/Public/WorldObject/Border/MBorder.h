// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "WorldObject/MWorldObject.h"
#include "MBorder.generated.h"

class UBoxComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMBorder final: public AMWorldObject
{
	GENERATED_BODY()
	
public:
	AMBorder();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* ExternalBoxComponent;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* InternalBoxComponent;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings")
	USoundBase* BorderCrossingSound;

	UPROPERTY()
	AActor* Player;

	FVector Location;

	UFUNCTION()
	void OnExternalBoxComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
	void OnInternalBoxComponentEndOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
