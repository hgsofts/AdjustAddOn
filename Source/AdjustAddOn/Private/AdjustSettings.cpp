// Copyright HGsofts, All Rights Reserved.

#include "AdjustSettings.h"

const UAdjustSettings* UAdjustSettings::Get()
{
	return UAdjustSettings::StaticClass()->GetDefaultObject<UAdjustSettings>();
}

bool UAdjustSettings::HasAppToken() const
{
	return !Config.AppToken.IsEmpty();
}
