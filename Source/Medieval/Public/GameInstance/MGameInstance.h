// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstance/Interfaces/MGameState.h"
#include "MGameInstance.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API UMGameInstance final: public UGameInstance, public IMGameState
{
	GENERATED_BODY()
	
public:
	virtual void NewGame() override;
	virtual void ReturnToMainMenu() override;
	virtual void QuitGame() const override;
	virtual void LevelLoaded() override;
	virtual FOnLevelStartedLoading& OnLevelStartedLoading() override;
	virtual FOnLevelLoaded& OnLevelLoaded() override;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Settings|Levels")
	TSoftObjectPtr<UWorld> GameLevel;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Levels")
	TSoftObjectPtr<UWorld> MainMenuLevel;

	UPROPERTY(EditDefaultsOnly, Category = "Settings|Audio")
	USoundBase* MusicSound;

	TSoftObjectPtr<UWorld> LoadingLevel;
	FOnLevelStartedLoading OnLevelStartedLoadingEvent;
	FOnLevelLoaded OnLevelLoadedEvent;

	UPROPERTY()
	UAudioComponent* AudioComponent;

	const float DelayBeforeLoading = 0.5f;

	void StartOpeningLevel(const TSoftObjectPtr<UWorld>& Level);
	void OpenLevel() const;
};
