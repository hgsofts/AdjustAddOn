// Copyright HGsofts, All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameplayTagContainer.h"
#include "AdjustEventEx.generated.h"


USTRUCT(BlueprintType)
struct FAdjustEventEx
{
    GENERATED_USTRUCT_BODY()

public:    
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust", meta = (Categories = "Adjust.Event"))
    FGameplayTag EventName;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    float Revenue;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString Currency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString TransactionId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    FString CallbackId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> CallbackParameters;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Adjust")
    TMap<FString, FString> PartnerParameters;
};
