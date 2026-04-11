// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Ch03HW08 : ModuleRules
{
	public Ch03HW08(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { //프로젝트에 사용된 공개된 모듈, 프로젝트에서 필수적으로 사용되는 기술들
			"Core",
			"CoreUObject",
			"Engine",
			"InputCore",
			"EnhancedInput",
			"UMG" //위젯 블루프린트와 관련된 모듈
		});

		PrivateDependencyModuleNames.AddRange(new string[] {  }); //

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
