// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BAIController.h"
#include "GameFramework/Character.h"
#include "Perception/AIPerceptionTypes.h"
#include "BAICharacter.generated.h"

class UAISenseConfig_Sight;
class UAIPerceptionComponent;

UCLASS()
class CASESTUDY_API ABAICharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABAICharacter();

protected:
	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAIPerceptionComponent* PerceptionComp;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UAISenseConfig_Sight* SightConfig;

	UFUNCTION()
	void OnPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus);

	virtual void BeginPlay() override;
	
};
