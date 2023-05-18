// Copyright Rob Meade. All Rights Reserved.

#include "Shop.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

#include "ShopSystem/Inventory/InventoryComponent.h"


AShop::AShop()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	if (StaticMeshComponent)
	{
		StaticMeshComponent->SetupAttachment(RootComponent);
	}

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	if (BoxComponent)
	{
		BoxComponent->SetupAttachment(RootComponent);
	}

	InventoryComponent = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	if (InventoryComponent)
	{
		AddOwnedComponent(InventoryComponent);
	}
}

void AShop::BeginPlay()
{
	Super::BeginPlay();
}

void AShop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UInventoryComponent* AShop::GetInventoryComponent() const
{
	return InventoryComponent;
}
