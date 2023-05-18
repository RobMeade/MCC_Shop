// Copyright Rob Meade. All Rights Reserved.


#include "SuccessModalWidget.h"

#include "Components/TextBlock.h"


void USuccessModalWidget::SetSuccessMessage(const FString& Message) const
{
	if (SuccessText)
	{
		SuccessText->SetText(FText::FromString(Message));
	}
}
