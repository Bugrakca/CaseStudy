// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CaseStudyGameMode.generated.h"

UCLASS(minimalapi)
class ACaseStudyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACaseStudyGameMode();

	virtual void BeginPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorClassToSpawn;

	void SpawnActorAtLocation(const FVector& Location);
};



