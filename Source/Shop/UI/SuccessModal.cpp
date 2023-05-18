// Copyright Rob Meade. All Rights Reserved.


#include "SuccessModal.h"

#include "Components/TextBlock.h"


void USuccessModal::SetSuccessMessage(const FString& Message) const
{
	if (SuccessText)
	{
		SuccessText->SetText(FText::FromString(Message));
	}
}
