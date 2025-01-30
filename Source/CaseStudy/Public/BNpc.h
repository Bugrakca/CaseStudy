// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BGameplayInterface.h"
#include "GameFramework/Actor.h"
#include "BNpc.generated.h"



class UBPopUpNpcWidget;

UCLASS()
class CASESTUDY_API ABNpc : public AActor, public IBGameplayInterface
{
private:
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ABNpc();

protected:
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* MeshComp;
	
	UPROPERTY()
	UBPopUpNpcWidget* PopupWidget;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY()
	TObjectPtr<APlayerController> PlayerController;

	UPROPERTY()
	int Str;
	
	UPROPERTY()
	int Dex;
	
	UPROPERTY()
	int Int;

	UPROPERTY()
	bool bIsMouseVisible;
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void TogglePopup();

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact_Implementation(APawn* InstigatorPawn) override;
};
