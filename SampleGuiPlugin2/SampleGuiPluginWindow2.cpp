/////////////////////////////////////////////////////////////////////////////
// Name:        SampleGuiPluginWindow2.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     18/09/2013 22:40:39
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

#include "SampleGuiPluginWindow2.h"
#include <wxGuiPluginBase.h>

////@begin XPM images
////@end XPM images


/*
 * SampleGuiPluginWindow2 type definition
 */

IMPLEMENT_DYNAMIC_CLASS( SampleGuiPluginWindow2, wxGuiPluginWindowBase )


/*
 * SampleGuiPluginWindow2 event table definition
 */

BEGIN_EVENT_TABLE( SampleGuiPluginWindow2, wxGuiPluginWindowBase )

////@begin SampleGuiPluginWindow2 event table entries
    EVT_WINDOW_DESTROY( SampleGuiPluginWindow2::OnDestroy )
////@end SampleGuiPluginWindow2 event table entries

END_EVENT_TABLE()


/*
 * SampleGuiPluginWindow2 constructors
 */

SampleGuiPluginWindow2::SampleGuiPluginWindow2()
{
    Init();
}

SampleGuiPluginWindow2::SampleGuiPluginWindow2( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
{
    Init();
    Create(plugin, parent, id, pos, size, style);
}


/*
 * SampleGuiPluginWindow2 creator
 */

bool SampleGuiPluginWindow2::Create( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style )
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
 * SampleGuiPluginWindow2 destructor
 */

SampleGuiPluginWindow2::~SampleGuiPluginWindow2()
{
////@begin SampleGuiPluginWindow2 destruction
////@end SampleGuiPluginWindow2 destruction
}


/*
 * Member initialisation
 */

void SampleGuiPluginWindow2::Init()
{
////@begin SampleGuiPluginWindow2 member initialisation
    m_MessageTextCtrl = NULL;
////@end SampleGuiPluginWindow2 member initialisation
}


/*
 * Control creation for SampleGuiPluginWindow2
 */

void SampleGuiPluginWindow2::CreateControls()
{    
////@begin SampleGuiPluginWindow2 content construction
    SampleGuiPluginWindow2* itemGuiPluginWindowBase1 = this;

    wxBoxSizer* itemBoxSizer2 = new wxBoxSizer(wxVERTICAL);
    itemGuiPluginWindowBase1->SetSizer(itemBoxSizer2);

    wxStaticText* itemStaticText3 = new wxStaticText( itemGuiPluginWindowBase1, wxID_STATIC, _("This text box receives messages from GUI Plugin 1:"), wxDefaultPosition, wxDefaultSize, 0 );
    itemBoxSizer2->Add(itemStaticText3, 0, wxALIGN_LEFT|wxLEFT|wxRIGHT|wxTOP, 5);

    m_MessageTextCtrl = new wxTextCtrl( itemGuiPluginWindowBase1, ID_GUI_PLUGIN2_MESSAGE_TEXTCTRL, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_READONLY );
    itemBoxSizer2->Add(m_MessageTextCtrl, 0, wxGROW|wxALL, 5);

    // Connect events and objects
    itemGuiPluginWindowBase1->Connect(ID_SAMPLEGUIPLUGINWINDOW2, wxEVT_DESTROY, wxWindowDestroyEventHandler(SampleGuiPluginWindow2::OnDestroy), NULL, this);
////@end SampleGuiPluginWindow2 content construction
	GetPlugin()->GetEventHandler()->Bind(wxEVT_GUI_PLUGIN_INTEROP, 
		wxCommandEventHandler(SampleGuiPluginWindow2::OnInteropMessageReceived), this);
}


/*
 * Should we show tooltips?
 */

bool SampleGuiPluginWindow2::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap SampleGuiPluginWindow2::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin SampleGuiPluginWindow2 bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end SampleGuiPluginWindow2 bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon SampleGuiPluginWindow2::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin SampleGuiPluginWindow2 icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end SampleGuiPluginWindow2 icon retrieval
}

void SampleGuiPluginWindow2::OnInteropMessageReceived(wxCommandEvent & event)
{
	m_MessageTextCtrl->SetValue(event.GetString());
}


/*
 * wxEVT_DESTROY event handler for ID_SAMPLEGUIPLUGINWINDOW2
 */

void SampleGuiPluginWindow2::OnDestroy( wxWindowDestroyEvent& event )
{
	GetPlugin()->GetEventHandler()->Unbind(wxEVT_GUI_PLUGIN_INTEROP,
		wxCommandEventHandler(SampleGuiPluginWindow2::OnInteropMessageReceived), this);
////@begin wxEVT_DESTROY event handler for ID_SAMPLEGUIPLUGINWINDOW2 in SampleGuiPluginWindow2.
    // Before editing this code, remove the block markers.
    event.Skip();
////@end wxEVT_DESTROY event handler for ID_SAMPLEGUIPLUGINWINDOW2 in SampleGuiPluginWindow2. 
}

