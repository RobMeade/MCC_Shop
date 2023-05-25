#pragma once

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"
#include "UObject/Interface.h"

#include "ShopInterface.generated.h"


UINTERFACE(MinimalAPI)
class UShopInterface : public UInterface
{
	GENERATED_BODY()
};

class SHOPSYSTEM_API IShopInterface
{
	GENERATED_BODY()


public:

	UFUNCTION()
	virtual void Interact() = 0;
};