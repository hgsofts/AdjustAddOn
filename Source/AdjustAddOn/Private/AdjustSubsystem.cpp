// Copyright HGsofts, All Rights Reserved.

#include "AdjustSubsystem.h"
#include "Adjust.h"
#include "AdjustSettings.h"
#include "AdjustAddOn.h"

#if PLATFORM_ANDROID
#include "Android/AndroidRuntimeSettings/Classes/AndroidRuntimeSettings.h"
#endif

void UAdjustSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const UAdjustSettings* const Settings = UAdjustSettings::Get();
	if (Settings->HasAppToken())
	{
		UAdjust::Initialize(Settings->GetConfig());

		UE_LOG(LogAdjustAddOn, Log, TEXT("Called UAdjust::Initialize [%s]"), *Settings->GetConfig().AppToken);
	}
}

void UAdjustSubsystem::Deinitialize()
{

}

FString UAdjustSubsystem::GetEventToken(FGameplayTag EventName)
{
	if (auto Token = UAdjustSettings::Get()->GetEvents().Find(EventName))
	{
		return Token->ToString();
	}

	UE_LOG(LogAdjustAddOn, Error, TEXT("GetEventToken [%s] - not included in Events.Contains"), *EventName.ToString());
	return TEXT("");
}

bool UAdjustSubsystem::TrackEventEx(const FAdjustEventEx& Event)
{
	if (UAdjust::IsEnabled())
	{
		if (auto Token = UAdjustSettings::Get()->GetEvents().Find(Event.EventName))
		{
			FName EventToken = *Token;
			if (!EventToken.IsNone())
			{
				FAdjustEvent NewEvent;
				NewEvent.EventToken = EventToken.ToString();
				NewEvent.Revenue = Event.Revenue;
				NewEvent.Currency = Event.Currency;
				NewEvent.TransactionId = Event.TransactionId;
				NewEvent.CallbackId = Event.CallbackId;
				NewEvent.CallbackParameters = Event.CallbackParameters;
				NewEvent.PartnerParameters = Event.PartnerParameters;
				UAdjust::TrackEvent(NewEvent);

				UE_LOG(LogAdjustAddOn, Log, TEXT("TrackEvent [%s] - Token [%s]"), *Event.EventName.ToString(), *EventToken.ToString());
				return true;
			}
			else
			{
				UE_LOG(LogAdjustAddOn, Error, TEXT("TrackEvent [%s] - Token is null"), *Event.EventName.ToString());
			}
		}
		else
		{
			UE_LOG(LogAdjustAddOn, Error, TEXT("TrackEvent [%s] - not included in Events.Contains"), *Event.EventName.ToString());
		}
	}
	else
	{
		UE_LOG(LogAdjustAddOn, Error, TEXT("Adjust is not enabled"));
	}

	return false;
}

int32 UAdjustSubsystem::StoreVersion()
{
#if PLATFORM_ANDROID
	UAndroidRuntimeSettings* Settings = UAndroidRuntimeSettings::StaticClass()->GetDefaultObject<UAndroidRuntimeSettings>();
	if (Settings)
	{
		return Settings->StoreVersion;
	}
#endif
	return -1;
}

FString UAdjustSubsystem::GetEventTags()
{
	FString Tags;

	for (auto Ele : UAdjustSettings::Get()->GetEvents())
	{
		Tags.Append(Ele.Key.ToString());
		Tags.Append(TEXT("\n"));
	}

	return Tags;
}
