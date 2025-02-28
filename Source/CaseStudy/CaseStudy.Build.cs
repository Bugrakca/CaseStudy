// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CaseStudy : ModuleRules
{
	public CaseStudy(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput", "UMG", "AIModule", "GameplayTasks" });
		
		// PrivateDependencyModuleNames.AddRange(new string[] { "SLate", "SlateCore" });
	}
}
