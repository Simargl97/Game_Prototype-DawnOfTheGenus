// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MSpawner.generated.h"

class UBoxComponent;

UCLASS()
class MEDIEVAL_API AMSpawner final: public AActor
{
	GENERATED_BODY()
	
public:	
	AMSpawner();

protected:
	UBoxComponent* BoxComponent;

	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "Settings")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (ClampMin = "0", UIMin = "0"))
	uint32 Count = 1;

	UPROPERTY(EditAnywhere, Category = "Settings", meta = (ClampMin = "0", UIMin = "0", Units = "Seconds"))
	float CheckRate = 1.0f;

	UPROPERTY()
	TArray<AActor*> Actors;

	FTimerHandle TimerHandle;

	void Spawn();
	FVector GetSpawnLocation() const;
	void Check();
};
