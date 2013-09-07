#pragma once

#include <wxNonGuiPluginBase.h>

// We need to know which DLL produced the specific plugin object.
WX_DECLARE_HASH_MAP(wxNonGuiPluginBase*, wxDynamicLibrary*, wxPointerHash, wxPointerEqual, wxNonGuiPluginToDllDictionary);
// We also need to keep the list of loaded DLLs
WX_DECLARE_LIST(wxDynamicLibrary, wxDynamicLibraryList);
// And separate list of loaded plugins for faster access.
WX_DECLARE_LIST(wxNonGuiPluginBase, wxNonGuiPluginBaseList);

class wxModularCoreSettings;

class wxModularCore
{
public:
	wxModularCore();
	virtual ~wxModularCore();

	virtual wxString GetPluginsPath(bool forceProgramPath) const;
	virtual wxString GetPluginExt();
	bool LoadPlugins(bool forceProgramPath);
	bool UnloadPlugins();

	void Clear();
private:
	bool LoadNonGuiPlugins(const wxString & pluginsDirectory);
	bool UnloadNonGuiPlugins();

	bool RegisterNonGuiPlugin(wxNonGuiPluginBase * plugin);
	bool UnRegisterNonGuiPlugin(wxNonGuiPluginBase * plugin);

	wxDynamicLibraryList m_DllList;
	wxNonGuiPluginToDllDictionary m_MapNonGuiPluginsDll;
	wxNonGuiPluginBaseList m_NonGuiPlugins;

	wxModularCoreSettings * m_Settings;
};