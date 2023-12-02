// Copyright HGsofts, All Rights Reserved.

using UnrealBuildTool;

public class AdjustAddOn : ModuleRules
{
	public AdjustAddOn(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {
				
			}
			);
				
		
// 		PrivateIncludePaths.AddRange(
// 			new string[] {
//                 "Plugins/Adjust/Source/Adjust/Public",
//             }
// 			);
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				
			}
			);
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
                "GameplayTags",
                "Adjust",
                //"DeveloperSettings"
            }
			);
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				
			}
			);

        if (Target.Platform == UnrealTargetPlatform.Android)
        {
            PrivateDependencyModuleNames.AddRange(
                new string[]
                {
                        "Launch",
                        "AndroidRuntimeSettings",
                }
                );
        }
    }
}
