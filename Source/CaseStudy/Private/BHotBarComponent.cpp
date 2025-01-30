// Fill out your copyright notice in the Description page of Project Settings.


#include "BHotBarComponent.h"
#include "BItemStruct.h"
#include "Blueprint/UserWidget.h"


// Sets default values for this component's properties
UBHotBarComponent::UBHotBarComponent()
{
	
}


// Called when the game starts

void UBHotBarComponent::BeginPlay()
{
	Super::BeginPlay();

	InitList(HotBarData, 4);
	
	if (WidgetClass)
	{
		HotBarWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
		UE_LOG(LogTemp, Log, TEXT("HotBarWidget Created"));
		HotBarWidget->AddToViewport();
		HotBarWidget->SetVisibility(ESlateVisibility::HitTestInvisible);
	}
}

int32 UBHotBarComponent::FindFirstAvailableSlot() const
{
	for (int32 EmptySlotIndex = 0; EmptySlotIndex < HotBarData.Num(); ++EmptySlotIndex)
	{
		if (HotBarData[EmptySlotIndex].Name.IsEmpty())
		{
			return EmptySlotIndex;
		}
	}

	return INDEX_NONE;
}

void UBHotBarComponent::InitList(TArray<FItemData>& Array, const int32 Size)
{
	FItemData EmptyItem{};

	for (int32 Index = 0; Index < Size; ++Index)
	{
		Array.Add(EmptyItem);
	}
	UE_LOG(LogTemp, Log, TEXT("Init The Inventory Array With Empty Struct"));
}

bool UBHotBarComponent::IsIndexEmpty(const int32 Index)
{
	UE_LOG(LogTemp, Log, TEXT("This is the InventoryComp IsIndexEmpty"));
	return !IsValid(HotBarData[Index].ItemClass);
}

void UBHotBarComponent::AddItem(const FItemData& Item)
{
	int32 NewSlotIndex = CreateNewItem(Item);
	OnSlotUpdate.Broadcast(NewSlotIndex);
	UE_LOG(LogTemp, Log, TEXT("FirstAvailableSlot: %d"), NewSlotIndex);
}

int32 UBHotBarComponent::CreateNewItem(const FItemData& Item)
{
	UE_LOG(LogTemp, Log, TEXT("This is the InventoryComp CreateNewItem"));

	if (const int32 AvailableSlot = FindFirstAvailableSlot(); AvailableSlot != INDEX_NONE)
	{
		HotBarData[AvailableSlot] = FItemData(Item);

		return AvailableSlot;
	}

	UE_LOG(LogTemp, Warning, TEXT("No empty slot found in inventory"));
	return INDEX_NONE;
}

FItemData& UBHotBarComponent::GetItemAtIndex(const int32 Index)
{
	return HotBarData[Index];
}




