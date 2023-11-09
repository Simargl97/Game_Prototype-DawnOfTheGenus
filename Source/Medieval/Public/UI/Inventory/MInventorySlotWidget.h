// Copyright (c). Medieval . Author: Sergoe Osipchuk

#pragma once

#include "CoreMinimal.h"
#include "UI/MUserWidget.h"
#include "MInventorySlotWidget.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnInventorySlotClicked, const FName&);

class UButton;
class UImage;
class UTextBlock;

struct FMItemSlot
{
	FName RowName;
	uint32 Count;
	bool bIsActive;
};

UCLASS(Abstract)
class MEDIEVAL_API UMInventorySlotWidget final: public UMUserWidget
{
	GENERATED_BODY()
	
public:
	FOnInventorySlotClicked OnInventorySlotClicked;

	virtual void NativeConstruct() override;
	void SetItem(const FMItemSlot& InItemSlot);

protected:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	UButton* InventorySlotButton;

	UPROPERTY(meta = (BindWidget))
	UImage* Thumbnail;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemName;

	UFUNCTION(BlueprintPure)
	bool IsActive() const;

private:
	FMItemSlot ItemSlot;

	UFUNCTION()
	void InventorySlotClicked();

	FText GetItemNameText(const FText& Name) const;
};
