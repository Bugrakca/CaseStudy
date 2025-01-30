// Fill out your copyright notice in the Description page of Project Settings.


#include "CaseStudy/Public/BNpc.h"

#include "BPopUpNpcWidget.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABNpc::ABNpc()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PopupWidget = nullptr;
	WidgetClass = nullptr;
	PlayerController = nullptr;
	bIsMouseVisible = false;

	Str = FMath::RandRange(1, 10);
	Dex = FMath::RandRange(1, 10);
	Int = FMath::RandRange(1, 10);

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComp"));
	SetRootComponent(MeshComp);
}

// Called when the game starts or when spawned
void ABNpc::BeginPlay()
{
	Super::BeginPlay();
	
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);

	if (PlayerController)
	{
		PlayerController->bShowMouseCursor = false;
		PlayerController->SetInputMode(FInputModeGameOnly());
	}
	
	if (WidgetClass)
	{
		PopupWidget = CreateWidget<UBPopUpNpcWidget>(GetWorld(), WidgetClass);
		UE_LOG(LogTemp, Log, TEXT("Widget Created: %s"), *PopupWidget->GetName());
		PopupWidget->AddToViewport(10);
		PopupWidget->SetVisibility(ESlateVisibility::Collapsed);
	}
}

// Called every frame

void ABNpc::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABNpc::Interact_Implementation(APawn* InstigatorPawn)
{
	if (!ensure(InstigatorPawn))
	{
		return;
	}

	if (!bIsMouseVisible)
	{
		FString NPCName = MeshComp->GetAttachmentRootActor()->GetName();
		
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("STR: %d"), Str));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("DEX: %d"), Dex));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, FString::Printf(TEXT("INT: %d"), Int));
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, NPCName);
	}

	TogglePopup();
}

void ABNpc::TogglePopup()
{
	if (PlayerController)
	{
		bIsMouseVisible = !bIsMouseVisible;

		if (bIsMouseVisible)
		{
			PlayerController->bShowMouseCursor = true;
			PlayerController->SetInputMode(FInputModeGameAndUI());
			PopupWidget->SetVisibility(ESlateVisibility::Visible);
		}
		else
		{
			PlayerController->bShowMouseCursor = false;
			PlayerController->SetInputMode(FInputModeGameOnly());
			PopupWidget->SetVisibility(ESlateVisibility::Collapsed);
		}
	}
}




