// Copyright Epic Games, Inc. All Rights Reserved.

#include "CaseStudyGameMode.h"

#include "EnvironmentQuery/EnvQueryManager.h"
#include "UObject/ConstructorHelpers.h"

ACaseStudyGameMode::ACaseStudyGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	SpawnTimeInterval = 5.0f;

}

void ACaseStudyGameMode::StartPlay()
{
	Super::StartPlay();

	TArray<FVector> SpawnLocations = {
		FVector(1700.0f, 1200.0f, 0.0f),  // Location 1
		FVector(1700.0f, 1300.0f, 0.0f), // Location 2
		FVector(1700.0f, 1400.0f, 0.0f) // Location 3
	};
	
	for (const FVector& Location : SpawnLocations)
	{
		SpawnActorAtLocation(Location);
	}
	

	GetWorldTimerManager().SetTimer(TimerHandle_AISpawn, this, &ACaseStudyGameMode::SpawnAITimerElapsed, SpawnTimeInterval, true);
}

void ACaseStudyGameMode::SpawnActorAtLocation(const FVector& Location)
{
	if (GetWorld())
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

		const FRotator DefaultRotation(0.0f, 75.0f, 0.0f);

		if (AActor* SpawnedActor = GetWorld()->SpawnActor<AActor>(ActorClassToSpawn, Location, DefaultRotation, SpawnParams))
		{
			UE_LOG(LogTemp, Warning, TEXT("Spawned Actor at Location: %s"), *Location.ToString());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("Failed to spawn Actor at Location: %s"), *Location.ToString());
		}
	}
}

void ACaseStudyGameMode::SpawnAITimerElapsed()
{
	UEnvQueryInstanceBlueprintWrapper* QueryInstance = UEnvQueryManager::RunEQSQuery(this, SpawnAIQuery, this, EEnvQueryRunMode::RandomBest5Pct, nullptr);
	if (QueryInstance)
	{
		QueryInstance->GetOnQueryFinishedEvent().AddDynamic(this, &ACaseStudyGameMode::OnQueryCompleted);
	}
}

void ACaseStudyGameMode::OnQueryCompleted(UEnvQueryInstanceBlueprintWrapper* QueryInstance, EEnvQueryStatus::Type QueryStatus)
{

	if (QueryStatus != EEnvQueryStatus::Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Spawn AI EQS Failed!"))
		return;
	}
	
	TArray<FVector> Locations = QueryInstance->GetResultsAsLocations();

	if (Locations.Num() > 0)
	{
		GetWorld()->SpawnActor<AActor>(AIClass, Locations[0], FRotator::ZeroRotator);
	}
}
