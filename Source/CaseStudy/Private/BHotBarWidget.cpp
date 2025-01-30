// Fill out your copyright notice in the Description page of Project Settings.


#include "BHotBarWidget.h"
#include "BHotBarComponent.h"
#include "Components/Image.h"
#include "Components/UniformGridPanel.h"

void UBHotBarWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	HotBarComp = GetOwningPlayerPawn()->GetComponentByClass<UBHotBarComponent>();
}

void UBHotBarWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (HotBarComp)
	{
		HotBarComp->OnSlotUpdate.AddDynamic(this, &UBHotBarWidget::GetItemSlotIndex);
	}
}

void UBHotBarWidget::UpdateSlot(int32 Index)
{
	FItemData& ItemData = HotBarComp->GetItemAtIndex(Index);
	UE_LOG(LogTemp, Log, TEXT("Item: %s"), *ItemData.Icon->GetName());
	
	if (Index == 0)
	{
		UE_LOG(LogTemp, Log, TEXT("Item is in First Slot"));
		SlotIcon->SetBrushFromTexture(ItemData.Icon);
		SlotIcon->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	else if (Index == 1)
	{
		UE_LOG(LogTemp, Log, TEXT("Item is in Third Slot"));
		SlotIcon1->SetBrushFromTexture(ItemData.Icon);
		SlotIcon1->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	else if (Index == 2)
	{
		UE_LOG(LogTemp, Log, TEXT("Item is in Second Slot"));
		SlotIcon2->SetBrushFromTexture(ItemData.Icon);
		SlotIcon2->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
	else if (Index == 3)
	{
		UE_LOG(LogTemp, Log, TEXT("Item is in Fourth Slot"));
		SlotIcon3->SetBrushFromTexture(ItemData.Icon);
		SlotIcon3->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

void UBHotBarWidget::GetItemSlotIndex(int32 SlotIndex)
{
	UE_LOG(LogTemp, Log, TEXT("SlotIndex: %d"), SlotIndex);
	UpdateSlot(SlotIndex);
}
