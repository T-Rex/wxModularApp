#pragma once

// We need to keep the list of loaded DLLs
WX_DECLARE_LIST(wxDynamicLibrary, wxDynamicLibraryList);

class wxModularCoreSettings;

class wxModularCore
{
public:
	wxModularCore();
	virtual ~wxModularCore();

	virtual wxString GetPluginsPath(bool forceProgramPath) const;
	virtual wxString GetPluginExt();

	virtual bool LoadAllPlugins(bool forceProgramPath) = 0;
	virtual bool UnloadAllPlugins() = 0;
	virtual void Clear();
protected:

	wxDynamicLibraryList m_DllList;

	wxModularCoreSettings * m_Settings;

	template<typename PluginType,
		typename PluginListType>
		bool RegisterPlugin(PluginType * plugin, 
		PluginListType & list)
	{
		list.Append(plugin);
		return true;
	}

	template<typename PluginType, 
		typename PluginListType,
		typename PluginToDllDictionaryType, 
		typename DeletePluginFunctionType> 
		bool UnRegisterPlugin(
			PluginType * plugin, 
			PluginListType & container, 
			PluginToDllDictionaryType & pluginMap)
	{
		PluginListType::compatibility_iterator it = 
			container.Find(plugin);
		if (it == NULL)
			return false;

		do 
		{
			wxDynamicLibrary * dll = (wxDynamicLibrary *)pluginMap[plugin];
			if (!dll) // Probably plugin was not loaded from dll
				break;

			wxDYNLIB_FUNCTION(DeletePluginFunctionType, 
				DeletePlugin, *dll);
			if (pfnDeletePlugin)
			{
				pfnDeletePlugin(plugin);
				container.Erase(it);
				pluginMap.erase(plugin);
				return true;
			}
		} while (false);

		// If plugin is not loaded from DLL (e.g. embedded into executable)
		wxDELETE(plugin);
		container.Erase(it);

		return true;
	}

	template<typename PluginType, 
		typename PluginListType,
		typename PluginToDllDictionaryType, 
		typename DeletePluginFunctionType> 
	bool UnloadPlugins(PluginListType & list, 
		PluginToDllDictionaryType & pluginDictoonary)
	{
		bool result = true;
		PluginType * plugin = NULL;
		while (list.GetFirst() && (plugin =  
			list.GetFirst()->GetData()))
		{
			result &= UnRegisterPlugin<PluginType, 
				PluginListType,
				PluginToDllDictionaryType, 
				DeletePluginFunctionType>(plugin, 
					list, pluginDictoonary);
		}
		return result;
	}

	template <typename PluginType, 
		typename PluginListType,
		typename PluginToDllDictionaryType, 
		typename CreatePluginFunctionType> 
	bool LoadPlugins(const wxString & pluginsDirectory, 
		PluginListType & list,
		PluginToDllDictionaryType & pluginDictionary,
		const wxString & subFolder)
	{
		wxFileName fn;
		fn.AssignDir(pluginsDirectory);
		wxLogDebug(wxT("%s"), fn.GetFullPath().data());
		fn.AppendDir(subFolder);
		wxLogDebug(wxT("%s"), fn.GetFullPath().data());
		if (!fn.DirExists())
			return false;

		if(!wxDirExists(fn.GetFullPath())) return false;
		wxString wildcard = wxString::Format(wxT("*.%s"), 
			GetPluginExt().GetData());
		wxArrayString pluginPaths;
		wxDir::GetAllFiles(fn.GetFullPath(), 
			&pluginPaths, wildcard);
		for(size_t i = 0; i < pluginPaths.GetCount(); ++i)
		{
			wxString fileName = pluginPaths[i];
			wxDynamicLibrary * dll = new wxDynamicLibrary(fileName);
			if (dll->IsLoaded())
			{
				wxDYNLIB_FUNCTION(CreatePluginFunctionType, 
					CreatePlugin, *dll);
				if (pfnCreatePlugin)
				{
					PluginType * plugin = pfnCreatePlugin();
					RegisterPlugin(plugin, list);
					m_DllList.Append(dll);
					pluginDictionary[plugin] = dll;
				}
				else
					wxDELETE(dll);
			}
		}
		return true;
	}

};