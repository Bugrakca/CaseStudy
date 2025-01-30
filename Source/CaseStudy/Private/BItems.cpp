// Fill out your copyright notice in the Description page of Project Settings.


#include "BItems.h"

#include "BHotBarComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ABItems::ABItems()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	RootComponent = SphereComp;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetupAttachment(SphereComp);
}


void ABItems::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	UBHotBarComponent* HotBarComp = Cast<UBHotBarComponent>(InstigatorPawn->GetComponentByClass(UBHotBarComponent::StaticClass()));
	HotBarComp->AddItem(ItemData);
	Destroy();
}

