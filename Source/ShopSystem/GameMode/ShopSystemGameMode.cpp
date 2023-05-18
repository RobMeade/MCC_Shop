// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShopSystemGameMode.h"
#include "ShopSystem/PlayerCharacter/ShopSystemCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShopSystemGameMode::AShopSystemGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ShopSystem/PlayerCharacter/BP_ShopSystemPlayerCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
