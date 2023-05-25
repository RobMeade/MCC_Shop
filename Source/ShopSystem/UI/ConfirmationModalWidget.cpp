// Copyright Rob Meade. All Rights Reserved.

#include "ConfirmationModalWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void UConfirmationModalWidget::SetConfirmationMessage(const FString& Message) const
{
	if (ConfirmationText)
	{
		ConfirmationText->SetText(FText::FromString(Message));
	}
}

void UConfirmationModalWidget::NativeConstruct()
{
	bIsFocusable = true;

	BindToUIEvents();
}

void UConfirmationModalWidget::BindToUIEvents()
{
	if (ConfirmButton)
	{
		ConfirmButton->OnClicked.AddDynamic(this, &UConfirmationModalWidget::OnClickedConfirmButton);
	}

	if (CancelButton)
	{
		CancelButton->OnClicked.AddDynamic(this, &UConfirmationModalWidget::OnClickedCancelButton);
	}
}

void UConfirmationModalWidget::OnClickedConfirmButton()
{
	OnConfirmButtonClicked.Broadcast();
}

void UConfirmationModalWidget::OnClickedCancelButton()
{
	OnCancelButtonClicked.Broadcast();
}
