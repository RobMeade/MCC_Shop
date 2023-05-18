// Copyright Rob Meade. All Rights Reserved.

#include "ConfirmationModalWidget.h"

#include "Components/TextBlock.h"


void UConfirmationModalWidget::SetConfirmationMessage(const FString& Message) const
{
	if (ConfirmationText)
	{
		ConfirmationText->SetText(FText::FromString(Message));
	}
}
