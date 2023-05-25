// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "ShopSystemPlayerController.generated.h"


// Forward Declarations
class UUserWidget;

class UConfirmationModalWidget;
class UFailedModalWidget;
class USuccessModalWidget;
class UShopWidget;


UCLASS()
class SHOPSYSTEM_API AShopSystemPlayerController : public APlayerController
{
	GENERATED_BODY()


public:


protected:

	virtual void BeginPlay() override;


private:

	void CreateUIWidgets();
	void BindToCharacterEvents();
	void BindToUIEvents();
	void ToggleWidgetVisibility(UUserWidget* Widget);
	void SetInputModeForUI(const UUserWidget* WidgetToFocus);
	void SetInputModeForGame();

	UFUNCTION()
	void DisplayShop();

	UFUNCTION()
	void BuyCurrency();

	UFUNCTION()
	void DisplayInventory();

	UFUNCTION()
	void ExitShop();

	/*
	 * UI Widgets
	 */
	UPROPERTY(EditAnywhere, Category = "User Interfaces")
	TSubclassOf<UUserWidget> ShopUserWidget = nullptr;

	UPROPERTY(EditAnywhere, Category = "User Interfaces")
	TSubclassOf<UUserWidget> ConfirmationModalUserWidget = nullptr;

	UPROPERTY(EditAnywhere, Category = "User Interfaces")
	TSubclassOf<UUserWidget> SuccessModalUserWidget = nullptr;

	UPROPERTY(EditAnywhere, Category = "User Interfaces")
	TSubclassOf<UUserWidget> FailedModalUserWidget = nullptr;

	UPROPERTY()
	UShopWidget* ShopWidget = nullptr;

	UPROPERTY()
	UConfirmationModalWidget* ConfirmationModalWidget = nullptr;

	UPROPERTY()
	USuccessModalWidget* SuccessModalWidget = nullptr;

	UPROPERTY()
	UFailedModalWidget* FailedModalWidget = nullptr;
};
