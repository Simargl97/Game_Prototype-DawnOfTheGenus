// Copyright (c). Medieval . Author: Sergoe Osipchuk


#include "GameInstance/MGameInstance.h"
#include "Components/AudioComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UMGameInstance::NewGame()
{
	StartOpeningLevel(GameLevel);
}

void UMGameInstance::StartOpeningLevel(const TSoftObjectPtr<UWorld>& Level)
{
	check(GetWorld());
	LoadingLevel = Level;
	OnLevelStartedLoadingEvent.Broadcast();

	UGameplayStatics::SetGamePaused(this, false);

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &ThisClass::OpenLevel, DelayBeforeLoading);
}

void UMGameInstance::OpenLevel() const
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, LoadingLevel);
}

void UMGameInstance::ReturnToMainMenu()
{
	StartOpeningLevel(MainMenuLevel);
}

void UMGameInstance::QuitGame() const
{
	UKismetSystemLibrary::QuitGame(this, GetPrimaryPlayerController(), EQuitPreference::Quit, true);
}

void UMGameInstance::LevelLoaded()
{
	OnLevelLoadedEvent.Broadcast();
	if (!AudioComponent)
	{
		AudioComponent = UGameplayStatics::SpawnSound2D(this, MusicSound, 1.0f, 1.0f, 0.0f, nullptr, true);
		check(AudioComponent);
		AudioComponent->Play();
	}
}

FOnLevelStartedLoading& UMGameInstance::OnLevelStartedLoading()
{
	return OnLevelStartedLoadingEvent;
}

FOnLevelLoaded& UMGameInstance::OnLevelLoaded()
{
	return OnLevelLoadedEvent;
}
