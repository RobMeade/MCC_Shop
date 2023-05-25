// Copyright Rob Meade. All Rights Reserved.


#include "SuccessModalWidget.h"

#include "Components/Button.h"
#include "Components/TextBlock.h"


void USuccessModalWidget::NativeConstruct()
{
	bIsFocusable = true;

	BindToUIEvents();
}

void USuccessModalWidget::BindToUIEvents()
{
	if (CloseButton)
	{
		CloseButton->OnClicked.AddDynamic(this, &USuccessModalWidget::OnClickedCloseButton);
	}
}

void USuccessModalWidget::OnClickedCloseButton()
{
	OnCloseButtonClicked.Broadcast();
}

void USuccessModalWidget::SetSuccessMessage(const FString& Message) const
{
	if (SuccessText)
	{
		SuccessText->SetText(FText::FromString(Message));
	}
}
