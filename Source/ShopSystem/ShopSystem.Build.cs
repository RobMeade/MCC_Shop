// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShopSystem : ModuleRules
{
	public ShopSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GameplayTags", "UMG" });

		PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
	}
}
