// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "Characters/Controllers/MAnimalAIController.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionComponent.h"
#include "Characters/Components/AI/MAIComponent.h"
#include "Characters/Components/AI/MPatrolAIComponent.h"
#include "Characters/Components/AI/MEscapeAIComponent.h"
#include "Characters/Components/AI/MAttackAIComponent.h"
#include "Characters/Interfaces/MPlayerInfo.h"
#include "Navigation/PathFollowingComponent.h"

AMAnimalAIController::AMAnimalAIController() : Super ()
{
	UAISenseConfig_Sight* SightSense = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightSense"));
	check(SightSense);
	SightSense->DetectionByAffiliation.bDetectNeutrals = true;

	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	check(AIPerceptionComponent);
	AIPerceptionComponent->ConfigureSense(*SightSense);
	AIPerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &ThisClass::OnTargetPerceptionUpdated);

	PatrolAIComponent = CreateDefaultSubobject<UMPatrolAIComponent>(TEXT("PatrolAIComponent"));

	EscapeAIComponent = CreateDefaultSubobject<UMEscapeAIComponent>(TEXT("EscapeAIComponent"));
	check(EscapeAIComponent);
	EscapeAIComponent->OnEscaped.AddUObject(this, &ThisClass::OnEscaped);

	AttackAIComponent = CreateDefaultSubobject<UMAttackAIComponent>(TEXT("AttackAIComponent"));
	check(AttackAIComponent);
	EscapeAIComponent->OnEscaped.AddUObject(this, &ThisClass::OnEscaped);
}

void AMAnimalAIController::OnTargetPerceptionUpdated(AActor* Actor, FAIStimulus Stimulus)
{
	if (Cast<IMPlayerInfo>(Actor))
	{
		check(EscapeAIComponent);
		EscapeAIComponent->SetEnemy(Actor);
		StartAIComponent(EscapeAIComponent);
	}
}

void AMAnimalAIController::OnEscaped()
{
	StartAIComponent(PatrolAIComponent);
}

void AMAnimalAIController::StartAIComponent(UMAIComponent* AIComponent)
{
	check(AIComponent);
	if (CurrentAIComponent != AIComponent)
	{
		if (CurrentAIComponent)
		{
			CurrentAIComponent->Stop();
		}
		CurrentAIComponent = AIComponent;
		CurrentAIComponent->Start(this);
	}
}

void AMAnimalAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);
	check(CurrentAIComponent);
	CurrentAIComponent->OnMoveCompleted(Result.IsSuccess());
}

void AMAnimalAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	check(InPawn);
	check(PatrolAIComponent);
	InPawn->OnTakePointDamage.AddDynamic(this, &ThisClass::PointDamage);

	PatrolAIComponent->SetStartLocation(InPawn->GetActorLocation());
	StartAIComponent(PatrolAIComponent);
}

void AMAnimalAIController::PointDamage(AActor* DamagedActor, float Damage, AController* InstigatedBy, FVector HitLocation, UPrimitiveComponent* FHitComponent, FName BoneName, FVector ShotFromDirection, const UDamageType* DamageType, AActor* DamageCauser)
{
	check(EscapeAIComponent);
	EscapeAIComponent->SetEnemy(DamageCauser);
	EscapeAIComponent->DamageHasBeenReceived();
	StartAIComponent(EscapeAIComponent);
}