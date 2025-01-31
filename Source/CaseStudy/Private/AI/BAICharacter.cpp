// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BAICharacter.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISense_Sight.h"


class ABCustomerQueueManager;
// Sets default values

ABAICharacter::ABAICharacter()
{
	PerceptionComp = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComp"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));

	if (SightConfig)
	{
		SightConfig->SightRadius = 1000.0f;
		SightConfig->LoseSightRadius = 1200.0f;
		SightConfig->PeripheralVisionAngleDegrees = 90.0f;
		SightConfig->SetMaxAge(5.0f);

		PerceptionComp->ConfigureSense(*SightConfig);
		PerceptionComp->SetDominantSense(UAISense_Sight::StaticClass());
	}
}

void ABAICharacter::BeginPlay()
{
	Super::BeginPlay();

	PerceptionComp->OnTargetPerceptionUpdated.AddDynamic(this, &ABAICharacter::OnPerceptionUpdated);
}

void ABAICharacter::OnPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus)
{
	APawn* SeenPawn = Cast<APawn>(UpdatedActor);
	if (SeenPawn && SeenPawn != this)
	{
		UBlackboardComponent* BlackboardComp = SeenPawn->GetController()->GetComponentByClass<UBlackboardComponent>();
		if (BlackboardComp)
		{
			BlackboardComp->SetValueAsObject("NextInLineTarget", SeenPawn);
		}
	}
}
