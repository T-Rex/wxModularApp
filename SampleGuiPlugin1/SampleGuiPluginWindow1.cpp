/////////////////////////////////////////////////////////////////////////////
// Name:        SampleGuiPluginWindow1.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     10/09/2013 00:01:49
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "SampleGuiPluginWindow1.h"
#include <wxGuiPluginBase.h>

////@begin XPM images
////@end XPM images


/*
 * SampleGuiPluginWindow1 type definition
 */

IMPLEMENT_DYNAMIC_CLASS( SampleGuiPluginWindow1, wxGuiPluginWindowBase )


/*
 * SampleGuiPluginWindow1 event table definition
 */

BEGIN_EVENT_TABLE( SampleGuiPluginWindow1, wxGuiPluginWindowBase )

////@begin SampleGuiPluginWindow1 event table entries
    EVT_BUTTON( ID_SEND_EVENT_BUTTON, SampleGuiPluginWindow1::OnSENDEVENTBUTTONClick )
////@end SampleGuiPluginWindow1 event table entries

END_EVENT_TABLE()


/*
 * SampleGuiPluginWindow1 constructors
 */

SampleGuiPluginWindow1::SampleGuiPluginWindow1()
{
    Init();
}

SampleGuiPluginWindow1::SampleGuiPluginWindow1( wxGuiPluginBase * plugin, 
											   wxWindow* parent, wxWindowID id, 
											   const wxPoint& pos, const wxSize& size, 
											   long style )
{
    Init();
    Create(plugin, parent, id, pos, size, style);
}


/*
 * SampleGuiPluginWindow1 creator
 */

bool SampleGuiPluginWindow1::Create(wxGuiPluginBase * plugin, 
									wxWindow* parent, wxWindowID id, 
									const wxPoint& pos, const wxSize& size, 
									long style )
{
    wxGuiPluginWindowBase::Create(plugin, parent, id, pos, size, style );

    CreateControls();
    if (GetSizer())
    {
        GetSizer()->SetSizeHints(this);
    }
    Centre();
    return true;
}


/*
 * SampleGuiPluginWindow1 destructor
 */

SampleGuiPluginWindow1::~SampleGuiPluginWindow1()
{
////@begin SampleGuiPluginWindow1 destruction
////@end SampleGuiPluginWindow1 destruction
}


/*
 * Member initialisation
 */

void SampleGuiPluginWindow1::Init()
{
////@begin SampleGuiPluginWindow1 member initialisation
    m_SamppleTextCtrl = NULL;
////@end SampleGuiPluginWindow1 member initialisation
}


/*
 * Control creation for SampleGuiPluginWindow1
 */

void SampleGuiPluginWindow1::CreateControls()
{    
////@begin SampleGuiPluginWindow1 content construction
    SampleGuiPluginWindow1* itemGuiPluginWindowBase1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemGuiPluginWindowBase1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemGuiPluginWindowBase1, wxID_STATIC, _("Enter some text here:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_SamppleTextCtrl = new wxTextCtrl( itemGuiPluginWindowBase1, ID_SAMPLE_TEXTCTRL, _("Hello, GUI Plugin 2!"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(m_SamppleTextCtrl, 0, wxGROW|wxLEFT|wxRIGHT|wxTOP, 5);

    wxButton* itemButton5 = new wxButton( itemGuiPluginWindowBase1, ID_SEND_EVENT_BUTTON, _("Send event"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemButton5, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5);

////@end SampleGuiPluginWindow1 content construction
}


/*
 * Should we show tooltips?
 */

bool SampleGuiPluginWindow1::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap SampleGuiPluginWindow1::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SampleGuiPluginWindow1 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end SampleGuiPluginWindow1 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon SampleGuiPluginWindow1::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SampleGuiPluginWindow1 icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end SampleGuiPluginWindow1 icon retrieval
}


/*
 * wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON
 */

void SampleGuiPluginWindow1::OnSENDEVENTBUTTONClick( wxCommandEvent& event )
{
	wxCommandEvent e(wxEVT_GUI_PLUGIN_INTEROP);
	e.SetString(m_SamppleTextCtrl->GetValue());
	GetPlugin()->GetEventHandler()->AddPendingEvent(e);

////@begin wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON in SampleGuiPluginWindow1.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON in SampleGuiPluginWindow1. 
}

