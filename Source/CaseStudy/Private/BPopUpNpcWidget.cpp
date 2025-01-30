// Fill out your copyright notice in the Description page of Project Settings.


#include "BPopUpNpcWidget.h"

#include "BInteractionComponent.h"
#include "CaseStudy/CaseStudyCharacter.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UBPopUpNpcWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (SectionOneButton)
	{
		SectionOneButton->OnClicked.AddDynamic(this, &UBPopUpNpcWidget::OnClickSectionOne);
	}

	if (SectionTwoButton)
	{
		SectionTwoButton->OnClicked.AddDynamic(this, &UBPopUpNpcWidget::OnClickSectionTwo);
	}

	if (SectionThreeButton)
	{
		SectionThreeButton->OnClicked.AddDynamic(this, &UBPopUpNpcWidget::OnClickSectionThree);
	}

	if (CloseButton)
	{
		CloseButton->OnClicked.AddDynamic(this, &UBPopUpNpcWidget::HidePopupWidget);
	}

	APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
	if (PlayerController)
	{
		Character = PlayerController->GetCharacter();
		if (Character)
		{
			UBInteractionComponent* InteractionComponent = Cast<UBInteractionComponent>(Character->GetComponentByClass(UBInteractionComponent::StaticClass()));
			InteractionComponent->OnInteractionDelegate.AddDynamic(this, &UBPopUpNpcWidget::GetActorSkeletalMesh);
		}
	}
}

void UBPopUpNpcWidget::OnClickSectionOne()
{
	UE_LOG(LogTemp, Log, TEXT("Button One Clicked"));

	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->PlayAnimation(RunAnimation, true);
	}
}

void UBPopUpNpcWidget::OnClickSectionTwo()
{
	UE_LOG(LogTemp, Log, TEXT("Button Two Clicked"));

	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->PlayAnimation(JumpAnimation, true);
	}
}

void UBPopUpNpcWidget::OnClickSectionThree()
{
	UE_LOG(LogTemp, Log, TEXT("Button Three Clicked"));

	if (SkeletalMeshComponent)
	{
		SkeletalMeshComponent->PlayAnimation(WalkAnimation, true);
	}
}

void UBPopUpNpcWidget::GetActorSkeletalMesh(AActor* HitActor)
{
	if (HitActor)
	{
		SkeletalMeshComponent = HitActor->FindComponentByClass<USkeletalMeshComponent>();
	}
}

void UBPopUpNpcWidget::HidePopupWidget()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	PlayerController->bShowMouseCursor = false;
	PlayerController->SetInputMode(FInputModeGameOnly());
	SetVisibility(ESlateVisibility::Collapsed);
}
