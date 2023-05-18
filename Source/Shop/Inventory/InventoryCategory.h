// Copyright Rob Meade. All Rights Reserved.

#pragma once

UENUM()
enum class EInventoryCategory : uint8
{

	None	UMETA(DisplayName = "Food"),
	Main	UMETA(DisplayName = "Utensils"),

	NUM		UMETA(Hidden)
};