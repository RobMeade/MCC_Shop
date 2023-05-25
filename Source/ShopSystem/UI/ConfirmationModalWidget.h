// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ConfirmationModalWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;

// Delegate Declarations
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConfirmationModalWidget_OnConfirmButtonClicked);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FConfirmationModalWidget_OnCancelButtonClicked);


UCLASS()
class SHOPSYSTEM_API UConfirmationModalWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void SetConfirmationMessage(const FString& Message) const;

	// Delegates
	FConfirmationModalWidget_OnConfirmButtonClicked OnConfirmButtonClicked;
	FConfirmationModalWidget_OnCancelButtonClicked OnCancelButtonClicked;


protected:

	virtual void NativeConstruct() override;


private:

	void BindToUIEvents();

	UFUNCTION()
	void OnClickedConfirmButton();

	UFUNCTION()
	void OnClickedCancelButton();

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ConfirmationText = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* ConfirmButton = nullptr;
	
};
