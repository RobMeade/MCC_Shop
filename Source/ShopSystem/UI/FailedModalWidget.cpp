// Copyright Rob Meade. All Rights Reserved.


#include "FailedModalWidget.h"

#include "Components/TextBlock.h"


void UFailedModalWidget::SetFailureMessage(const FString& Message) const
{
	if (FailureText)
	{
		FailureText->SetText(FText::FromString(Message));
	}
}
