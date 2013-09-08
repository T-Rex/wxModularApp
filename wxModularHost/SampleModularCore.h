#pragma once

#include <wxModularCore.h>
#include <wxNonGuiPluginBase.h>
#include <wxGuiPluginBase.h>

// We need to know which DLL produced the specific plugin object.
WX_DECLARE_HASH_MAP(wxNonGuiPluginBase*, wxDynamicLibrary*, \
					wxPointerHash, wxPointerEqual, \
					wxNonGuiPluginToDllDictionary);
WX_DECLARE_HASH_MAP(wxGuiPluginBase*, wxDynamicLibrary*, \
					wxPointerHash, wxPointerEqual, \
					wxGuiPluginToDllDictionary);
// And separate list of loaded plugins for faster access.
WX_DECLARE_LIST(wxNonGuiPluginBase, wxNonGuiPluginBaseList);
WX_DECLARE_LIST(wxGuiPluginBase, wxGuiPluginBaseList);

class SampleModularCore : public wxModularCore
{
public:
	virtual ~SampleModularCore();
	virtual bool LoadAllPlugins(bool forceProgramPath);
	virtual bool UnloadAllPlugins();

	const wxNonGuiPluginBaseList & GetNonGuiPlugins() const;
private:
	wxNonGuiPluginToDllDictionary m_MapNonGuiPluginsDll;
	wxNonGuiPluginBaseList m_NonGuiPlugins;
	wxGuiPluginToDllDictionary m_MapGuiPluginsDll;
	wxGuiPluginBaseList m_GuiPlugins;
};