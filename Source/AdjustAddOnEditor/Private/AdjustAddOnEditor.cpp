// Copyright HGsofts, All Rights Reserved.

#include "AdjustAddOnEditor.h"
#include "PropertyEditorModule.h"
#include "ISettingsModule.h"
#include "ISettingsSection.h"
#include "ISettingsContainer.h"
#include "AdjustSettings.h"

#define LOCTEXT_NAMESPACE "FAdjustAddOnEditorModule"

void FAdjustAddOnEditorModule::StartupModule()
{	
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor");
	
	RegisterObjectCustomizations();

	PropertyModule.NotifyCustomizationModuleChanged();		

}

void FAdjustAddOnEditorModule::RegisterObjectCustomizations()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		ISettingsSectionPtr SettingsSection = SettingsModule->RegisterSettings("Project", "Plugins", "Adjust",
			LOCTEXT("AdjustSettingsName", "Adjust"),
			LOCTEXT("AdjustSettingsDescription", "Configure the Adjust settings."),
			GetMutableDefault<UAdjustSettings>());
	}	
}
	 
void FAdjustAddOnEditorModule::RegisterCustomClassLayout(FName ClassName, FOnGetDetailCustomizationInstance DetailLayoutDelegate)
{
	check(ClassName != NAME_None);

	RegisteredClassNames.Add(ClassName);

	static FName PropertyEditor("PropertyEditor");
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);
	PropertyModule.RegisterCustomClassLayout(ClassName, DetailLayoutDelegate);
}


void FAdjustAddOnEditorModule::RegisterCustomPropertyTypeLayout(FName PropertyTypeName, FOnGetPropertyTypeCustomizationInstance PropertyTypeLayoutDelegate)
{
	check(PropertyTypeName != NAME_None);

	RegisteredPropertyTypes.Add(PropertyTypeName);

	static FName PropertyEditor("PropertyEditor");
	FPropertyEditorModule& PropertyModule = FModuleManager::GetModuleChecked<FPropertyEditorModule>(PropertyEditor);
	PropertyModule.RegisterCustomPropertyTypeLayout(PropertyTypeName, PropertyTypeLayoutDelegate);
}

void FAdjustAddOnEditorModule::ShutdownModule()
{
	ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings");
	if (SettingsModule != nullptr)
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "Adjust");
	}

	if (FModuleManager::Get().IsModuleLoaded("PropertyEditor"))
	{
		auto& PropertyModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");

		// Unregister all classes customized by name
		for (auto It = RegisteredClassNames.CreateConstIterator(); It; ++It)
		{
			if (It->IsValid())
			{
				PropertyModule.UnregisterCustomClassLayout(*It);
			}
		}

		// Unregister all structures
		for (auto It = RegisteredPropertyTypes.CreateConstIterator(); It; ++It)
		{
			if (It->IsValid())
			{
				PropertyModule.UnregisterCustomPropertyTypeLayout(*It);
			}
		}

		PropertyModule.NotifyCustomizationModuleChanged();
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FAdjustAddOnEditorModule, AdjustAddOnEditor)