// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"



// Sets default values
ABAIController::ABAIController()
{
	
}

// Called when the game starts or when spawned

void ABAIController::BeginPlay()
{
	Super::BeginPlay();

	RunBehaviorTree(BehaviorTree);

	FActorSpawnParameters SpawnParams;
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;

	FVector SpawnLocation = {2200.0f, 2300.0f, 0.0f};

	AActor* TableActor = GetWorld()->SpawnActor<AActor>(TableClass, SpawnLocation, FRotator(0.0f, 10.0f, 0.0f), SpawnParams);

	GetBlackboardComponent()->SetValueAsObject("TargetActor", TableActor);
}


void ABAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	if (Result.Code == EPathFollowingResult::Success)
	{
		if (UBlackboardComponent* BlackBoardComp = GetBlackboardComponent())
		{
			BlackBoardComp->SetValueAsBool("IsWaiting", true);
		}
		
		UE_LOG(LogTemp, Warning, TEXT("AI reached its destination!"));
	}
}

