// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ShopWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;


UCLASS()
class SHOPSYSTEM_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()


public:


protected:


private:

	UPROPERTY(meta = (BindWidget))
	UButton* BuyCurrencyButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GoldCoins = nullptr;

};
