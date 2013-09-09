/////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiPluginWindowBase.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     09/09/2013 23:54:21
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

#include "wxGuiPluginWindowBase.h"
#include "wxGuiPluginBase.h"

////@begin XPM images
////@end XPM images


/*
 * wxGuiPluginWindowBase type definition
 */

IMPLEMENT_DYNAMIC_CLASS( wxGuiPluginWindowBase, wxPanel )


/*
 * wxGuiPluginWindowBase event table definition
 */

BEGIN_EVENT_TABLE( wxGuiPluginWindowBase, wxPanel )

////@begin wxGuiPluginWindowBase event table entries
////@end wxGuiPluginWindowBase event table entries

END_EVENT_TABLE()


/*
 * wxGuiPluginWindowBase constructors
 */

wxGuiPluginWindowBase::wxGuiPluginWindowBase()
{
    Init();
}

wxGuiPluginWindowBase::wxGuiPluginWindowBase(wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
    Init();
    Create(plugin, parent, id, pos, size, style);
}


/*
 * wxGuiPluginWindowBase creator
 */

bool wxGuiPluginWindowBase::Create(wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style)
{
	m_Plugin = plugin;
////@begin wxGuiPluginWindowBase creation
    wxPanel::Create(parent, id, pos, size, style);
    CreateControls();
////@end wxGuiPluginWindowBase creation
    return true;
}


/*
 * wxGuiPluginWindowBase destructor
 */

wxGuiPluginWindowBase::~wxGuiPluginWindowBase()
{
////@begin wxGuiPluginWindowBase destruction
////@end wxGuiPluginWindowBase destruction
}


/*
 * Member initialisation
 */

void wxGuiPluginWindowBase::Init()
{
////@begin wxGuiPluginWindowBase member initialisation
////@end wxGuiPluginWindowBase member initialisation
}


/*
 * Control creation for wxGuiPluginWindowBase
 */

void wxGuiPluginWindowBase::CreateControls()
{    
////@begin wxGuiPluginWindowBase content construction
////@end wxGuiPluginWindowBase content construction
}


/*
 * Should we show tooltips?
 */

bool wxGuiPluginWindowBase::ShowToolTips()
{
    return true;
}

/*
 * Get bitmap resources
 */

wxBitmap wxGuiPluginWindowBase::GetBitmapResource( const wxString& name )
{
    // Bitmap retrieval
////@begin wxGuiPluginWindowBase bitmap retrieval
    wxUnusedVar(name);
    return wxNullBitmap;
////@end wxGuiPluginWindowBase bitmap retrieval
}

/*
 * Get icon resources
 */

wxIcon wxGuiPluginWindowBase::GetIconResource( const wxString& name )
{
    // Icon retrieval
////@begin wxGuiPluginWindowBase icon retrieval
    wxUnusedVar(name);
    return wxNullIcon;
////@end wxGuiPluginWindowBase icon retrieval
}
