// Fill out your copyright notice in the Description page of Project Settings.


#include "CaseStudy/Public/BInteractionComponent.h"

#include "CaseStudy/Public/BGameplayInterface.h"


// Sets default values for this component's properties
UBInteractionComponent::UBInteractionComponent()
{
	InteractionDistance = 500.0f;
	SphereRadius = 40.0f;
}

void UBInteractionComponent::PrimaryInteract()
{
	FCollisionObjectQueryParams ObjectQueryParams;
	ObjectQueryParams.AddObjectTypesToQuery(ECC_WorldDynamic);

	AActor* MyOwner = GetOwner();

	FVector EyeLocation;
	FRotator EyeRotation;
	MyOwner->GetActorEyesViewPoint(EyeLocation, EyeRotation);

	FVector End = EyeLocation + (EyeRotation.Vector() * InteractionDistance);

	FCollisionShape CollisionShape;
	CollisionShape.SetSphere(SphereRadius);

	TArray<FHitResult> HitsResults;

	bool bBlockHit = GetWorld()->SweepMultiByObjectType(HitsResults, EyeLocation, End, FQuat::Identity, ObjectQueryParams, CollisionShape);

	FColor LineColor = bBlockHit ? FColor::Green : FColor::Red;

	for (FHitResult Hit : HitsResults)
	{
		DrawDebugSphere(GetWorld(), Hit.ImpactPoint, SphereRadius, 12, LineColor, false, 2.0f);

		if (AActor* HitActor = Hit.GetActor())
		{
			if (HitActor->Implements<UBGameplayInterface>())
			{
				APawn* MyPawn = Cast<APawn>(MyOwner);

				OnInteractionDelegate.Broadcast(HitActor);

				IBGameplayInterface::Execute_Interact(HitActor, MyPawn);
				break;
			}
		}
	}
}