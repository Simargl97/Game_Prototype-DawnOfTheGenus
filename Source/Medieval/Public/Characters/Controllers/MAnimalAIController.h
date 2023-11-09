// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Characters/Interfaces/MMovement.h"
#include "MAnimalAIController.generated.h"

class UMAIComponent;
class UMPatrolAIComponent;
class UMEscapeAIComponent;
class UMAttackAIComponent;

UCLASS(Abstract)
class MEDIEVAL_API AMAnimalAIController final: public AAIController
{
	GENERATED_BODY()
	
public:
	AMAnimalAIController();
	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

protected:
	UPROPERTY(VisibleAnywhere, Category = "Settings")
	UAIPerceptionComponent* AIPerceptionComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMPatrolAIComponent* PatrolAIComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMEscapeAIComponent* EscapeAIComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Components")
	UMAttackAIComponent* AttackAIComponent;

	virtual void OnPossess(APawn* InPawn) override;

private:

	UPROPERTY()
	UMAIComponent* CurrentAIComponent;

	UFUNCTION()
	void OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus);

	UFUNCTION()
	void PointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation,
				UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection,
				const  UDamageType* DamageType, AActor* DamageCauser);

	void OnEscaped();
	void StartAIComponent(UMAIComponent* AIComponent);

};
