// Copyright Rob Meade. All Rights Reserved.

#include "ShopSystemPlayerController.h"

#include "Blueprint/UserWidget.h"

#include "ShopSystem/PlayerCharacter/ShopSystemCharacter.h"
#include "ShopSystem/UI/ConfirmationModalWidget.h"
#include "ShopSystem/UI/FailedModalWidget.h"
#include "ShopSystem/UI/ShopWidget.h"
#include "ShopSystem/UI/SuccessModalWidget.h"


void AShopSystemPlayerController::BeginPlay()
{
	Super::BeginPlay();

	CreateUIWidgets();
	BindToCharacterEvents();
	BindToUIEvents();
	UpdateGoldCoins(GoldCoins);
}

void AShopSystemPlayerController::CreateUIWidgets()
{
	if (ShopUserWidget)
	{
		ShopWidget = CreateWidget<UShopWidget>(this, ShopUserWidget);
		ShopWidget->AddToViewport(0);
		ToggleWidgetVisibility(ShopWidget);
	}

	if (ConfirmationModalUserWidget)
	{
		ConfirmationModalWidget = CreateWidget<UConfirmationModalWidget>(this,ConfirmationModalUserWidget);
		ConfirmationModalWidget->AddToViewport(1);
		ToggleWidgetVisibility(ConfirmationModalWidget);		
	}

	if (SuccessModalUserWidget)
	{
		SuccessModalWidget = CreateWidget<USuccessModalWidget>(this, SuccessModalUserWidget);
		SuccessModalWidget->AddToViewport(1);
		ToggleWidgetVisibility(SuccessModalWidget);	
	}

	if (FailedModalUserWidget)
	{
		FailedModalWidget = CreateWidget<UFailedModalWidget>(this,FailedModalUserWidget);
		FailedModalWidget->AddToViewport(1);
		ToggleWidgetVisibility(FailedModalWidget);		
	}
}

void AShopSystemPlayerController::BindToCharacterEvents()
{
	if (AShopSystemCharacter* ShopSystemCharacter = Cast<AShopSystemCharacter>(GetCharacter()))
	{
		ShopSystemCharacter->OnShopEntered.AddDynamic(this, &AShopSystemPlayerController::DisplayShop);
	}
}


void AShopSystemPlayerController::BindToUIEvents()
{
	if (ShopWidget)
	{
		ShopWidget->OnBuyCurrencyButtonClicked.AddDynamic(this, &AShopSystemPlayerController::BuyCurrency);
		ShopWidget->OnShopButtonClicked.AddDynamic(this, &AShopSystemPlayerController::DisplayShop);
		ShopWidget->OnInventoryButtonClicked.AddDynamic(this, &AShopSystemPlayerController::DisplayInventory);
		ShopWidget->OnExitButtonClicked.AddDynamic(this, &AShopSystemPlayerController::ExitShop);
	}

	if (ConfirmationModalWidget)
	{
		// TODO: Bind to events
	}

	if (SuccessModalWidget)
	{
		SuccessModalWidget->OnCloseButtonClicked.AddDynamic(this, &AShopSystemPlayerController::CloseSuccessModal);
	}

	if (FailedModalWidget)
	{
		FailedModalWidget->OnCloseButtonClicked.AddDynamic(this, &AShopSystemPlayerController::CloseFailedModal);
	}
}

void AShopSystemPlayerController::ToggleWidgetVisibility(UUserWidget* Widget)
{
	if (Widget)
	{
		switch (Widget->GetVisibility())
		{
			case ESlateVisibility::Collapsed:
				Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
				break;
			case ESlateVisibility::Hidden:				
				Widget->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
				break;
			case ESlateVisibility::HitTestInvisible:
				Widget->SetVisibility(ESlateVisibility::Hidden);
				break;
			case ESlateVisibility::SelfHitTestInvisible:
				Widget->SetVisibility(ESlateVisibility::Hidden);
				break;
			case ESlateVisibility::Visible:
				Widget->SetVisibility(ESlateVisibility::Hidden);
				break;
			default:
				UE_LOG(LogTemp, Error, TEXT("Unexpected ESlateVisibility Value."));
				break;
		}
	}
}

void AShopSystemPlayerController::SetInputModeForUI(const UUserWidget* WidgetToFocus)
{
	if (WidgetToFocus)
	{
		FInputModeUIOnly InputModeUIOnly;
		InputModeUIOnly.SetWidgetToFocus(WidgetToFocus->GetCachedWidget());		
		SetInputMode(InputModeUIOnly);

		bShowMouseCursor = true;		
	}
}

void AShopSystemPlayerController::SetInputModeForGame()
{
	const FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);

	bShowMouseCursor = false;
}

void AShopSystemPlayerController::UpdateGoldCoins(const int32& Value) const
{
	if (ShopWidget)
	{
		ShopWidget->UpdateGoldCoins(Value);
	}
}

void AShopSystemPlayerController::DisplayShop()
{
	ToggleWidgetVisibility(ShopWidget);
	SetInputModeForUI(ShopWidget);
}

void AShopSystemPlayerController::BuyCurrency()
{
	// TODO: Stripped down process, just give some Gold Coins
	GoldCoins += 100;

	if (SuccessModalWidget)
	{
		SuccessModalWidget->SetSuccessMessage("You have bought 100 Gold Coins");
		ToggleWidgetVisibility(SuccessModalWidget);
		SetInputModeForUI(SuccessModalWidget);
	}

	UpdateGoldCoins(GoldCoins);
}

void AShopSystemPlayerController::DisplayInventory()
{
	// TODO: Display Inventory
}

void AShopSystemPlayerController::ExitShop()
{
	ToggleWidgetVisibility(ShopWidget);
	SetInputModeForGame();
}

void AShopSystemPlayerController::CloseSuccessModal()
{
	ToggleWidgetVisibility(SuccessModalWidget);
	SetInputModeForUI(ShopWidget);
}

void AShopSystemPlayerController::CloseFailedModal()
{
	ToggleWidgetVisibility(FailedModalWidget);
	SetInputModeForUI(ShopWidget);
}
