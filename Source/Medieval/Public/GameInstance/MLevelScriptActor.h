// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "MLevelScriptActor.generated.h"

UCLASS(Abstract)
class MEDIEVAL_API AMLevelScriptActor final: public ALevelScriptActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

private:
	void TestDelayLoading() const;
};
