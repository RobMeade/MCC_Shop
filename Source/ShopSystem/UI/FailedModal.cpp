// Copyright Rob Meade. All Rights Reserved.


#include "FailedModal.h"

#include "Components/TextBlock.h"


void UFailedModal::SetFailureMessage(const FString& Message) const
{
	if (FailureText)
	{
		FailureText->SetText(FText::FromString(Message));
	}
}
