// Copyright Rob Meade. All Rights Reserved.

#include "ShopWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UShopWidget::NativeConstruct()
{
	bIsFocusable = true;

	BindToUIEvents();
}

void UShopWidget::BindToUIEvents()
{
	if (BuyCurrencyButton)
	{
		BuyCurrencyButton->OnClicked.AddDynamic(this, &UShopWidget::OnClickedBuyCurrencyButton);
	}

	if (ShopButton)
	{
		ShopButton->OnClicked.AddDynamic(this, &UShopWidget::OnClickedShopButton);
	}
	
	if (InventoryButton)
	{
		InventoryButton->OnClicked.AddDynamic(this, &UShopWidget::OnClickedInventoryButton);
	}

	if (ExitButton)
	{
		ExitButton->OnClicked.AddDynamic(this, &UShopWidget::OnClickedExitButton);
	}
}

void UShopWidget::OnClickedBuyCurrencyButton()
{
	OnBuyCurrencyButtonClicked.Broadcast();
}

void UShopWidget::OnClickedShopButton()
{
	OnShopButtonClicked.Broadcast();
}

void UShopWidget::OnClickedInventoryButton()
{
	OnInventoryButtonClicked.Broadcast();
}

void UShopWidget::OnClickedExitButton()
{
	OnExitButtonClicked.Broadcast();
}

void UShopWidget::UpdateGoldCoins(const int32& Value) const
{
	if (GoldCoins)
	{
		const FString ValueString = FString::FromInt(Value);
		GoldCoins->SetText(FText::FromString(ValueString));
	}
}
