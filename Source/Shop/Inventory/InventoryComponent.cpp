// Copyright Rob Meade. All Rights Reserved.


#include "InventoryComponent.h"

// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

TArray<UInventoryItem*> UInventoryComponent::GetInventoryItems() const
{
	return InventoryItems;
}
