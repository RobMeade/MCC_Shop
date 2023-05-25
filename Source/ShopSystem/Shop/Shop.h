// Copyright Rob Meade. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "ShopInterface.h"

#include "Shop.generated.h"


// Forward Declarations
class UBoxComponent;
class UInventoryComponent;


UCLASS()
class SHOPSYSTEM_API AShop : public AActor, public IShopInterface
{
	GENERATED_BODY()


public:	

	AShop();

	virtual void Tick(float DeltaTime) override;

	UInventoryComponent* GetInventoryComponent() const;

	virtual void Interact() override;


protected:

	virtual void BeginPlay() override;


private:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UBoxComponent* BoxComponent = nullptr;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Inventory", meta = (AllowPrivateAccess = "true"))
	UInventoryComponent* InventoryComponent = nullptr;
};
