// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BGameplayInterface.h"
#include "BItemStruct.h"
#include "GameFramework/Actor.h"
#include "BItems.generated.h"

class USphereComponent;

UCLASS()
class CASESTUDY_API ABItems : public AActor, public IBGameplayInterface
{

private:
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABItems();

protected:
	UPROPERTY(VisibleAnywhere)
	USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* MeshComp;
	
	UPROPERTY(EditDefaultsOnly, Category = "Item Data")
	FItemData ItemData;


public:
	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
