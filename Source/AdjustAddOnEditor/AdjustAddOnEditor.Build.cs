// Copyright HGsofts, All Rights Reserved.

using UnrealBuildTool;

public class AdjustAddOnEditor : ModuleRules
{
	public AdjustAddOnEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				
			}
			);
				
		
		PrivateIncludePaths.AddRange(
			new string[] {
                "AdjustAddOn/Public",
                "AdjustAddOnEditor/Public",
            }
			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "InputCore"
            }
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "Core",
                "CoreUObject",                
                "Engine",
                "UnrealEd",
                "Slate",
                "SlateCore",                                
                "Settings",
                "GameplayTags",                
                "Adjust",
                "AdjustAddOn"                
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
			}
			);
	}
}
