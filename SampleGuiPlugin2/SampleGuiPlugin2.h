#pragma once

#include <wxGuiPluginBase.h>

class SampleGuiPlugin2 : public wxGuiPluginBase
{
	DECLARE_DYNAMIC_CLASS(SampleGuiPlugin2)
public:
	SampleGuiPlugin2();
	SampleGuiPlugin2(wxEvtHandler * handler);
	virtual ~SampleGuiPlugin2();

	virtual wxString GetName() const;
	virtual wxString GetId() const;
	virtual wxWindow * CreatePanel(wxWindow * parent);
};