#include "stdwx.h"
#include "wxModularCore.h"
#include "wxModularCoreSettings.h"
#include <wx/listimpl.cpp>

WX_DEFINE_LIST(wxDynamicLibraryList);


wxModularCore::wxModularCore()
	:m_Settings(new wxModularCoreSettings)
{
	// This will allow to delete all objects from this list automatically
	m_DllList.DeleteContents(true);
}

wxModularCore::~wxModularCore()
{
	wxDELETE(m_Settings);
}

void wxModularCore::Clear()
{
	UnloadAllPlugins();
	// TODO: Add the code which resets the object to initial state
}

wxString wxModularCore::GetPluginsPath(bool forceProgramPath) const
{
	wxString path;
	if (m_Settings->GetStoreInAppData() && !forceProgramPath)
		path = wxStandardPaths::Get().GetConfigDir();
	else
		path = wxPathOnly(wxStandardPaths::Get().GetExecutablePath());
	wxFileName fn;
	fn.AssignDir(path);
	fn.AppendDir(wxT("plugins"));
	return fn.GetFullPath();
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
