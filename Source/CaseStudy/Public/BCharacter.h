// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BGameplayInterface.h"
#include "GameFramework/Character.h"
#include "BCharacter.generated.h"

UCLASS()
class CASESTUDY_API ABCharacter : public ACharacter, public IBGameplayInterface
{
private:
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABCharacter();

protected:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* MeshComp;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
