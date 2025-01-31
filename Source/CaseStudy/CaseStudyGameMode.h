// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryTypes.h"
#include "GameFramework/GameModeBase.h"
#include "CaseStudyGameMode.generated.h"


class ABCustomerQueueManager;

UCLASS(minimalapi)
class ACaseStudyGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACaseStudyGameMode();

	virtual void StartPlay() override;

protected:
	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorClassToSpawn;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	float SpawnTimeInterval;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TObjectPtr<UEnvQuery> SpawnAIQuery;

	UPROPERTY(EditDefaultsOnly, Category = "AI")
	TSubclassOf<AActor> AIClass;
	
	FTimerHandle TimerHandle_AISpawn;

	UFUNCTION()
	void SpawnAITimerElapsed();

	void SpawnActorAtLocation(const FVector& Location);

	UFUNCTION()
	void OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus);
};



