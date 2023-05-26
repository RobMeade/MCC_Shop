// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ShopWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;


// Delegate Declarations
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShopWidget_OnBuyCurrencyButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShopWidget_OnShopButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShopWidget_OnInventoryButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FShopWidget_OnExitButtonClicked);


UCLASS()
class SHOPSYSTEM_API UShopWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void UpdateGoldCoins(const int32& Value) const;

	// Delegates
	FShopWidget_OnBuyCurrencyButtonClicked OnBuyCurrencyButtonClicked;
	FShopWidget_OnShopButtonClicked OnShopButtonClicked;
	FShopWidget_OnInventoryButtonClicked OnInventoryButtonClicked;
	FShopWidget_OnExitButtonClicked OnExitButtonClicked;


protected:

	virtual void NativeConstruct() override;


private:

	void BindToUIEvents();

	UFUNCTION()
	void OnClickedBuyCurrencyButton();

	UFUNCTION()
	void OnClickedShopButton();

	UFUNCTION()
	void OnClickedInventoryButton();

	UFUNCTION()
	void OnClickedExitButton();

	UPROPERTY(meta = (BindWidget))
	UButton* BuyCurrencyButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* ShopButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* InventoryButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* ExitButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* GoldCoins = nullptr;
};
