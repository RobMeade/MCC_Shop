// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShopGameMode.h"
#include "Shop/PlayerCharacter/ShopCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShopGameMode::AShopGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Shop/PlayerCharacter/BP_ShopPlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
