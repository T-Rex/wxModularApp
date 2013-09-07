#pragma once

#include "Declarations.h"

class DEMO_API wxNonGuiPluginBase : public wxObject
{
	DECLARE_ABSTRACT_CLASS(wxNonGuiPluginBase)
public:
	wxNonGuiPluginBase();
	virtual ~wxNonGuiPluginBase();
	
	virtual int Work() = 0;
};

typedef wxNonGuiPluginBase * (*CreatePlugin_function)();
typedef void (*DeletePlugin_function)(wxNonGuiPluginBase * plugin);