// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"

#include "InventoryComponent.generated.h"


// Forward Declarations
class UInventoryItem;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SHOPSYSTEM_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInventoryComponent();

	TArray<UInventoryItem*> GetInventoryItems() const;


protected:


private:	

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TArray<UInventoryItem*> InventoryItems;
};
