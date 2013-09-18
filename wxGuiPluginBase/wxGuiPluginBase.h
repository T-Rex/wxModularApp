#pragma once

#include "Declarations.h"

class DEMO_API wxGuiPluginBase : public wxObject
{
	DECLARE_ABSTRACT_CLASS(wxGuiPluginBase)
public:
	wxGuiPluginBase(wxEvtHandler * handler);
	virtual ~wxGuiPluginBase();
	
	virtual wxString GetName() const = 0;
	virtual wxString GetId() const = 0;
	virtual wxWindow * CreatePanel(wxWindow * parent) = 0;

	wxEvtHandler * GetEventHandler();
	virtual void SetEventHandler(wxEvtHandler * handler);
protected:
	wxEvtHandler * m_Handler;
};

DECLARE_EXPORTED_EVENT_TYPE(DEMO_API, wxEVT_GUI_PLUGIN_INTEROP, wxEVT_USER_FIRST + 100)

typedef wxGuiPluginBase * (*CreateGuiPlugin_function)();
typedef void (*DeleteGuiPlugin_function)(wxGuiPluginBase * plugin);