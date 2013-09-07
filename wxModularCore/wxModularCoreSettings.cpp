#include "stdwx.h"
#include "wxModularCoreSettings.h"

wxModularCoreSettings::wxModularCoreSettings()
	: m_bStoreInAppData(false)
{

}

wxModularCoreSettings::wxModularCoreSettings(const wxModularCoreSettings & settings)
{
	CopyFrom(settings);
}

wxModularCoreSettings & wxModularCoreSettings::operator = (const wxModularCoreSettings & settings)
{
	if (this != &settings)
	{
		CopyFrom(settings);
	}
	return *this;
}

wxModularCoreSettings::~wxModularCoreSettings()
{

}

void wxModularCoreSettings::CopyFrom(const wxModularCoreSettings & settings)
{
	m_bStoreInAppData = settings.m_bStoreInAppData;
}

void wxModularCoreSettings::SetStoreInAppData(const bool & value)
{
	m_bStoreInAppData = value;
}

bool wxModularCoreSettings::GetStoreInAppData() const
{
	return m_bStoreInAppData;
}