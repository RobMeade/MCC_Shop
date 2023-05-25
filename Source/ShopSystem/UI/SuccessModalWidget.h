// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "SuccessModalWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;

// Delegate Declarations
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FSuccessModalWidget_OnCloseButtonClicked);


UCLASS()
class SHOPSYSTEM_API USuccessModalWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void SetSuccessMessage(const FString& Message) const;

	// Delegates
	FSuccessModalWidget_OnCloseButtonClicked OnCloseButtonClicked;

protected:

	virtual void NativeConstruct() override;


private:

	void BindToUIEvents();

	UFUNCTION()
	void OnClickedCloseButton();

	UPROPERTY(meta = (BindWidget))
	UTextBlock* SuccessText = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* CloseButton = nullptr;
};
