// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "GameInstance/MLevelScriptActor.h"
#include "GameInstance/Interfaces/MGameState.h"

void AMLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &ThisClass::TestDelayLoading, 2.0f);
}

void AMLevelScriptActor::TestDelayLoading() const
{
	IMGameState* GameState = Cast<IMGameState>(GetGameInstance());
	check(GameState);
	GameState->LevelLoaded();
}
