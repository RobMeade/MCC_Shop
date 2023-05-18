// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "ConfirmationModal.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;


UCLASS()
class SHOP_API UConfirmationModal : public UUserWidget
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
