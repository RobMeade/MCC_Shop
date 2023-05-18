// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ConfirmationModalWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;


UCLASS()
class SHOPSYSTEM_API UConfirmationModalWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void SetConfirmationMessage(const FString& Message) const;


protected:


private:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* ConfirmationText = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelButton = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* ConfirmButton = nullptr;
	
};
