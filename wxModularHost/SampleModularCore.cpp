#include "stdwx.h"
#include "SampleModularCore.h"
#include <wx/listimpl.cpp>

WX_DEFINE_LIST(wxNonGuiPluginBaseList);
WX_DEFINE_LIST(wxGuiPluginBaseList);

SampleModularCore::~SampleModularCore()
{
	Clear();
}

bool SampleModularCore::LoadAllPlugins(bool forceProgramPath)
{
	wxString pluginsRootDir = GetPluginsPath(forceProgramPath);
	bool result = true;
	result &= LoadPlugins<wxNonGuiPluginBase,
		wxNonGuiPluginBaseList,
		wxNonGuiPluginToDllDictionary,
		CreatePlugin_function>(pluginsRootDir,
		m_NonGuiPlugins, 
		m_MapNonGuiPluginsDll,
		wxT("nongui"));
	result &= LoadPlugins<wxGuiPluginBase,
		wxGuiPluginBaseList,
		wxGuiPluginToDllDictionary,
		CreateGuiPlugin_function>(pluginsRootDir,
		m_GuiPlugins, 
		m_MapGuiPluginsDll,
		wxT("gui"));
	// You can implement other logic which takes in account
	// the result of LoadPlugins() calls
	for(wxGuiPluginBaseList::Node * node = m_GuiPlugins.GetFirst(); 
		node; node = node->GetNext())
	{
		wxGuiPluginBase * plugin = node->GetData();
		plugin->SetEventHandler(m_Handler);
	}
	return true;
}

bool SampleModularCore::UnloadAllPlugins()
{
	return 
		UnloadPlugins<wxNonGuiPluginBase,
			wxNonGuiPluginBaseList,
			wxNonGuiPluginToDllDictionary,
			DeletePlugin_function>(m_NonGuiPlugins, 
			m_MapNonGuiPluginsDll) &&
		UnloadPlugins<wxGuiPluginBase,
			wxGuiPluginBaseList,
			wxGuiPluginToDllDictionary,
			DeleteGuiPlugin_function>(m_GuiPlugins, 
			m_MapGuiPluginsDll);
}

const wxNonGuiPluginBaseList & SampleModularCore::GetNonGuiPlugins() const
{
	return m_NonGuiPlugins;
}

const wxGuiPluginBaseList & SampleModularCore::GetGuiPlugins() const
{
	return m_GuiPlugins;
}