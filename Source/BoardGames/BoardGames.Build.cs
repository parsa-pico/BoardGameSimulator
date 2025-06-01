// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BoardGames : ModuleRules
{
	public BoardGames(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
