#include "stdwx.h"
#include "wxGuiPluginBase.h"

DEFINE_EVENT_TYPE(wxEVT_GUI_PLUGIN_INTEROP)

IMPLEMENT_ABSTRACT_CLASS(wxGuiPluginBase, wxObject)

wxGuiPluginBase::wxGuiPluginBase(wxEvtHandler * handler)
: m_Handler(handler)
{
}

wxGuiPluginBase::~wxGuiPluginBase()
{
}

wxEvtHandler * wxGuiPluginBase::GetEventHandler()
{
	return m_Handler;
}

void wxGuiPluginBase::SetEventHandler(wxEvtHandler * handler)
{
	m_Handler = handler;
}