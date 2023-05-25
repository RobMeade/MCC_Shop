// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FailedModalWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;

// Delegate Declarations
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FFailedModalWidget_OnCloseButtonClicked);


UCLASS()
class SHOPSYSTEM_API UFailedModalWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void SetFailureMessage(const FString& Message) const;

	// Delegates
	FFailedModalWidget_OnCloseButtonClicked OnCloseButtonClicked;


protected:

	virtual void NativeConstruct() override;


private:

	void BindToUIEvents();

	UFUNCTION()
	void OnClickedCloseButton();


	UPROPERTY(meta = (BindWidget))
	UTextBlock* FailureText = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* CloseButton = nullptr;
};
