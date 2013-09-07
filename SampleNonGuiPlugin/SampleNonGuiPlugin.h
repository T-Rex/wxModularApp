#pragma once

#include <wxNonGuiPluginBase.h>

class SampleNonGuiPlugin : public wxNonGuiPluginBase
{
	DECLARE_DYNAMIC_CLASS(SampleNonGuiPlugin)
public:
	SampleNonGuiPlugin();
	virtual ~SampleNonGuiPlugin();
	
	virtual int Work();
};