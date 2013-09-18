#pragma once

#include <wxGuiPluginBase.h>

class SampleGuiPlugin1 : public wxGuiPluginBase
{
	DECLARE_DYNAMIC_CLASS(SampleGuiPlugin1)
public:
	SampleGuiPlugin1();
	SampleGuiPlugin1(wxEvtHandler * handler);
	virtual ~SampleGuiPlugin1();

	virtual wxString GetName() const;
	virtual wxString GetId() const;
	virtual wxWindow * CreatePanel(wxWindow * parent);
};