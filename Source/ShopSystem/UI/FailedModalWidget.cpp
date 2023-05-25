// Copyright Rob Meade. All Rights Reserved.


#include "FailedModalWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UFailedModalWidget::NativeConstruct()
{
	bIsFocusable = true;

	BindToUIEvents();
}

void UFailedModalWidget::BindToUIEvents()
{
	if (CloseButton)
	{
		CloseButton->OnClicked.AddDynamic(this, &UFailedModalWidget::OnClickedCloseButton);
	}
}

void UFailedModalWidget::OnClickedCloseButton()
{
	OnCloseButtonClicked.Broadcast();
}

void UFailedModalWidget::SetFailureMessage(const FString& Message) const
{
	if (FailureText)
	{
		FailureText->SetText(FText::FromString(Message));
	}
}
