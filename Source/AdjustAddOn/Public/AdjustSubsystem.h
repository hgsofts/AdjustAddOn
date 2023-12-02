// Copyright HGsofts, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "AdjustEventEx.h"
#include "AdjustSubsystem.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ADJUSTADDON_API UAdjustSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;

public:
	UFUNCTION(BlueprintCallable, Category = "Adjust", meta = (Categories = "Adjust.Event"))
    FString GetEventToken(FGameplayTag EventName);

	UFUNCTION(BlueprintCallable, Category = "Adjust")
    bool TrackEventEx(const FAdjustEventEx& Event);

	UFUNCTION(BlueprintCallable, Category="Android")
	int32 StoreVersion();

	// for debug
	UFUNCTION(BlueprintCallable, Category="Adjust")
	FString GetEventTags();
};
