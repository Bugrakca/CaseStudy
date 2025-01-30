// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BItemStruct.h"
#include "Components/ActorComponent.h"
#include "BHotBarComponent.generated.h"

class UBHotBarWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnSlotUpdate, int32, Index);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class CASESTUDY_API UBHotBarComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UBHotBarComponent();

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSubclassOf<UUserWidget> WidgetClass;

	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UUserWidget> HotBarWidget;
	
	int32 FindFirstAvailableSlot() const;

	void InitList(TArray<FItemData>& Array, const int32 Size);
	
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	UPROPERTY(BlueprintReadOnly)
	TArray<FItemData> HotBarData;

	UPROPERTY(BlueprintAssignable)
	FOnSlotUpdate OnSlotUpdate;

	UFUNCTION(BlueprintCallable)
	bool IsIndexEmpty(const int32 Index);

	void AddItem(const FItemData& Item);

	int32 CreateNewItem(const FItemData& Item);

	UFUNCTION()
	FItemData& GetItemAtIndex(const int32 Index);
};
