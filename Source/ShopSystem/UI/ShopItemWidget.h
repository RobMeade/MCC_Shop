// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ShopItemWidget.generated.h"


// Forward Declarations
class UButton;
class UImage;
class UTextBlock;


UCLASS()
class SHOPSYSTEM_API UShopItemWidget : public UUserWidget
{
	GENERATED_BODY()


public:


protected:


private:

	UPROPERTY(meta = (BindWidget))
	UImage* ItemImage = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemName = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemDescription = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ItemCost = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* BuyNowButton = nullptr;
};
