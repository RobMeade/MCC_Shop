// Copyright Rob Meade. All Rights Reserved.

#include "ConfirmationModal.h"

#include "Components/TextBlock.h"


void UConfirmationModal::SetConfirmationMessage(const FString& Message) const
{
	if (ConfirmationText)
	{
		ConfirmationText->SetText(FText::FromString(Message));
	}
}
