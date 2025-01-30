// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BInteractionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnActorHit, AActor*, HitActor);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CASESTUDY_API UBInteractionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBInteractionComponent();

protected:
	UPROPERTY(VisibleAnywhere)
	float InteractionDistance;
	
	UPROPERTY(VisibleAnywhere)
	float SphereRadius;

public:
	void PrimaryInteract();

	UPROPERTY()
	FOnActorHit OnInteractionDelegate;
};
