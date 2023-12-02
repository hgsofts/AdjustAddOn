// Copyright HGsofts, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "AdjustConfig.h"
#include "GameplayTagContainer.h"

#include "AdjustSettings.generated.h"

UCLASS(config=Engine, defaultconfig)
class ADJUSTADDON_API UAdjustSettings : public UObject
{
	GENERATED_BODY()

public:
	static const UAdjustSettings* Get();

	const TMap<FGameplayTag, FName>& GetEvents() const { return Events; }

	const FAdjustConfig& GetConfig() const { return Config; }

	bool HasAppToken() const;

protected:
	UPROPERTY(config, EditAnywhere, Category = "Adjust")
	FAdjustConfig Config;

	/** Tag filtered "Adjust.Event" */
	UPROPERTY(config, EditAnywhere, Category = "Adjust", meta = (ForceInlineRow, Categories = "Adjust.Event"))
	TMap<FGameplayTag, FName> Events;
};
