// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BPopUpNpcWidget.generated.h"

class UButton;
class UTextBlock;
/**
 * 
 */
UCLASS()
class CASESTUDY_API UBPopUpNpcWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> SectionOneButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> SectionTwoButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> SectionThreeButton;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UButton> CloseButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<ACharacter> Character;

	UPROPERTY(BlueprintReadOnly)
	USkeletalMeshComponent* SkeletalMeshComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAnimSequence> RunAnimation;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAnimSequence> WalkAnimation;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UAnimSequence> JumpAnimation;

	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnClickSectionOne();
	UFUNCTION()
	void OnClickSectionTwo();
	UFUNCTION()
	void OnClickSectionThree();

	UFUNCTION()
	void GetActorSkeletalMesh(AActor* HitActor);

	UFUNCTION()
	void HidePopupWidget();
};
