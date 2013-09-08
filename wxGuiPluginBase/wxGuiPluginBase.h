#pragma once

#include "Declarations.h"

class DEMO_API wxGuiPluginBase : public wxObject
{
	DECLARE_ABSTRACT_CLASS(wxGuiPluginBase)
public:
	wxGuiPluginBase();
	virtual ~wxGuiPluginBase();
	
	virtual wxString GetName() = 0;
	virtual wxString GetId() = 0;
	virtual wxWindow * CreatePanel() = 0;
};

typedef wxGuiPluginBase * (*CreateGuiPlugin_function)();
typedef void (*DeleteGuiPlugin_function)(wxGuiPluginBase * plugin);