#include "stdwx.h"
#include "wxModularCore.h"
#include "wxModularCoreSettings.h"
#include <wx/listimpl.cpp>

WX_DEFINE_LIST(wxDynamicLibraryList);


wxModularCore::wxModularCore()
	: m_Settings(new wxModularCoreSettings), m_Handler(new wxEvtHandler)
{
	// This will allow to delete all objects from this list automatically
	m_DllList.DeleteContents(true);
}

wxModularCore::~wxModularCore()
{
	wxDELETE(m_Handler);
	wxDELETE(m_Settings);
}

void wxModularCore::Clear()
{
	UnloadAllPlugins();
	// TODO: Add the code which resets the object to initial state
}

wxString wxModularCore::GetPluginsPath(bool forceProgramPath) const
{
#if defined(__WXMAC__)
	return wxStandardPaths::Get().GetPluginsDir();
#else
	wxString path;
	if (m_Settings->GetStoreInAppData() && !forceProgramPath)
		path = wxStandardPaths::Get().GetConfigDir();
	else
		path = wxPathOnly(wxStandardPaths::Get().GetExecutablePath());
	wxFileName fn;
	fn.AssignDir(path);
	fn.AppendDir(wxT("plugins"));
	return fn.GetFullPath();
#endif
}

wxString wxModularCore::GetPluginExt()
{
	return 
#if defined(__WXMSW__)
		wxT("dll");
#elif defined(__WXGTK__)
		wxT("so");
#elif defined(__WXMAC__)
		wxT("dylib");
#else
		wxEmptyString;
#endif
}
