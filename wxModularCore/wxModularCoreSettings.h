#pragma once

class wxModularCoreSettings
{
public:
	wxModularCoreSettings();
	wxModularCoreSettings(const wxModularCoreSettings & settings);
	wxModularCoreSettings & operator = (const wxModularCoreSettings & settings);
	virtual ~wxModularCoreSettings();

	void SetStoreInAppData(const bool & val);
	bool GetStoreInAppData() const;
protected:
	virtual void CopyFrom(const wxModularCoreSettings & settings);
private:
	bool m_bStoreInAppData; // Should we store data in Application Data folder or in .exe folder
};