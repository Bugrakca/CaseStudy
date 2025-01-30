// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BHotBarWidget.generated.h"

class UUniformGridPanel;
class UBHotBarComponent;
class UImage;
class UTextBlock;
/**
 * 
 */
UCLASS()
class CASESTUDY_API UBHotBarWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> SlotIcon;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> SlotIcon1;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> SlotIcon2;
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	TObjectPtr<UImage> SlotIcon3;

	virtual void NativeConstruct() override;

	virtual void NativeOnInitialized() override;

	UFUNCTION()
	void UpdateSlot(int32 Index);

	UFUNCTION()
	void GetItemSlotIndex(int32 SlotIndex);

public:
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UBHotBarComponent> HotBarComp;
};
