// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "FailedModalWidget.generated.h"


// Forward Declarations
class UButton;
class UTextBlock;


UCLASS()
class SHOPSYSTEM_API UFailedModalWidget : public UUserWidget
{
	GENERATED_BODY()


public:

	void SetFailureMessage(const FString& Message) const;


protected:


private:

	UPROPERTY(meta = (BindWidget))
	UTextBlock* FailureText = nullptr;

	UPROPERTY(meta = (BindWidget))
	UButton* CloseButton = nullptr;
};
