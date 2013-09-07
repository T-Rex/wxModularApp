#include "stdwx.h"
#include "wxModularCore.h"
#include "wxModularCoreSettings.h"
#include <wx/listimpl.cpp>
WX_DEFINE_LIST(wxDynamicLibraryList);
WX_DEFINE_LIST(wxNonGuiPluginBaseList);

wxModularCore::wxModularCore()
	:m_Settings(new wxModularCoreSettings)
{
	// This will allow to delete all objects from this list automatically
	m_DllList.DeleteContents(true);
}

wxModularCore::~wxModularCore()
{
	Clear();
	wxDELETE(m_Settings);
}

void wxModularCore::Clear()
{
	UnloadPlugins();
	// TODO: Add the core which resets the object to initial state
}

bool wxModularCore::LoadPlugins(bool forceProgramPath)
{
	wxString pluginsRootDir = GetPluginsPath(forceProgramPath);
	
	wxFileName fn;
	fn.AssignDir(pluginsRootDir);
	wxLogDebug(wxT("%s"), fn.GetFullPath().data());
	fn.AppendDir(wxT("plugins"));
	wxLogDebug(wxT("%s"), fn.GetFullPath().data());
	if (!fn.DirExists())
		return false;

	return LoadNonGuiPlugins(fn.GetFullPath());
}

bool wxModularCore::UnloadPlugins()
{
	return UnloadNonGuiPlugins();
}

bool wxModularCore::LoadNonGuiPlugins(const wxString & pluginsDirectory)
{
	wxFileName fn;
	fn.AssignDir(pluginsDirectory);
	wxLogDebug(wxT("%s"), fn.GetFullPath().data());
	fn.AppendDir(wxT("nongui"));
	wxLogDebug(wxT("%s"), fn.GetFullPath().data());
	if (!fn.DirExists())
		return false;

	if(!wxDirExists(fn.GetFullPath())) return false;
	wxString wildcard = wxString::Format(wxT("*.%s"), GetPluginExt().GetData());
	wxArrayString pluginPaths;
	wxDir::GetAllFiles(fn.GetFullPath(), &pluginPaths, wildcard);
	for(size_t i = 0; i < pluginPaths.GetCount(); ++i)
	{
		wxString fileName = pluginPaths[i];
		wxDynamicLibrary * dll = new wxDynamicLibrary(fileName);
		if (dll->IsLoaded())
		{
			wxDYNLIB_FUNCTION(CreatePlugin_function, CreatePlugin, *dll);
			if (pfnCreatePlugin)
			{
				wxNonGuiPluginBase* plugin = pfnCreatePlugin();
				RegisterNonGuiPlugin(plugin);
				m_DllList.Append(dll);
				m_MapNonGuiPluginsDll[plugin] = dll;
			}
			else
				wxDELETE(dll);
		}
	}

	return true;
}

bool wxModularCore::UnloadNonGuiPlugins()
{
	bool result = true;
	wxNonGuiPluginBase * plugin = NULL;
	while (m_NonGuiPlugins.GetFirst() && (plugin =  m_NonGuiPlugins.GetFirst()->GetData()))
	{
		result &= UnRegisterNonGuiPlugin(plugin);
	}
	return result;
}

wxString wxModularCore::GetPluginsPath(bool forceProgramPath /* = false */) const
{
	wxString path;
	if (m_Settings->GetStoreInAppData() && !forceProgramPath)
		path = wxStandardPaths::Get().GetConfigDir();
	else
		path = wxPathOnly(wxStandardPaths::Get().GetExecutablePath());
	return path;
}

wxString wxModularCore::GetPluginExt()
{
	return 
#if defined(__WXMSW__)
		wxT("dll");
#else
		wxT("so");
#endif
}

bool wxModularCore::RegisterNonGuiPlugin(wxNonGuiPluginBase * plugin)
{
	m_NonGuiPlugins.Append(plugin);
	return true;
}

bool wxModularCore::UnRegisterNonGuiPlugin(wxNonGuiPluginBase * plugin)
{
	wxNonGuiPluginBaseList::compatibility_iterator it = m_NonGuiPlugins.Find(plugin);
	if (it == NULL)
		return false;

	do 
	{
		wxDynamicLibrary * dll = m_MapNonGuiPluginsDll[plugin];
		if (!dll) // Probably plugin was not loaded from dll
			break;

		wxDYNLIB_FUNCTION(DeletePlugin_function, DeletePlugin, *dll);
		if (pfnDeletePlugin)
		{
			pfnDeletePlugin(plugin);
			m_NonGuiPlugins.Erase(it);
			m_MapNonGuiPluginsDll.erase(plugin);
			return true;
		}
	} while (false);

	// If plugin is not loaded from DLL (e.g. embedded into executable)
	wxDELETE(plugin);
	m_NonGuiPlugins.Erase(it);

	return true;
}

const wxNonGuiPluginBaseList & wxModularCore::GetNonGuiPlugins() const
{
	return m_NonGuiPlugins;
}