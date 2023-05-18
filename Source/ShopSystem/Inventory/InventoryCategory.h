// Copyright Rob Meade. All Rights Reserved.

#pragma once

UENUM()
enum class EInventoryCategory : uint8
{
	None		UMETA(DisplayName = "None"),
	Food		UMETA(DisplayName = "Food"),
	Utensils	UMETA(DisplayName = "Utensils"),

	NUM			UMETA(Hidden)
};