/////////////////////////////////////////////////////////////////////////////
// Name:        wxModularHostApp.cpp
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     02/08/2013 21:14:33
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

// For compilers that support precompilation, includes "wx/wx.h".
#include "stdwx.h"

#ifdef __BORLANDC__
#pragma hdrstop
#endif

#ifndef WX_PRECOMP
#include "wx/wx.h"
#endif

////@begin includes
////@end includes

#include "wxModularHostApp.h"
#include <wxModularCore.h>

////@begin XPM images
////@end XPM images


/*
 * Application instance implementation
 */

////@begin implement app
IMPLEMENT_APP( wxModularHostApp )
////@end implement app


/*
 * wxModularHostApp type definition
 */

IMPLEMENT_CLASS( wxModularHostApp, wxApp )


/*
 * wxModularHostApp event table definition
 */

BEGIN_EVENT_TABLE( wxModularHostApp, wxApp )

////@begin wxModularHostApp event table entries
////@end wxModularHostApp event table entries

END_EVENT_TABLE()


/*
 * Constructor for wxModularHostApp
 */

wxModularHostApp::wxModularHostApp()
{
    Init();
}


/*
 * Member initialisation
 */

void wxModularHostApp::Init()
{
////@begin wxModularHostApp member initialisation
	m_PluginManager = new wxModularCore;
////@end wxModularHostApp member initialisation
}

/*
 * Initialisation for wxModularHostApp
 */

bool wxModularHostApp::OnInit()
{    
#if wxUSE_XPM
	wxImage::AddHandler(new wxXPMHandler);
#endif
#if wxUSE_LIBPNG
	wxImage::AddHandler(new wxPNGHandler);
#endif
#if wxUSE_LIBJPEG
	wxImage::AddHandler(new wxJPEGHandler);
#endif
#if wxUSE_GIF
	wxImage::AddHandler(new wxGIFHandler);
#endif
	if(m_PluginManager)
	{
		m_PluginManager->LoadPlugins(true);
	}
	MainFrame* mainWindow = new MainFrame( NULL );
	mainWindow->Show(true);

    return true;
}


/*
 * Cleanup for wxModularHostApp
 */

int wxModularHostApp::OnExit()
{    
	wxDELETE(m_PluginManager);
////@begin wxModularHostApp cleanup
	return wxApp::OnExit();
////@end wxModularHostApp cleanup
}

