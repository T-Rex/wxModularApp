/////////////////////////////////////////////////////////////////////////////
// Name:        SampleGuiPluginWindow2.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     18/09/2013 22:40:39
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _SAMPLEGUIPLUGINWINDOW2_H_
#define _SAMPLEGUIPLUGINWINDOW2_H_


/*!
 * Includes
 */

////@begin includes
////@end includes
#include <wxGuiPluginWindowBase.h>

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_SAMPLEGUIPLUGINWINDOW2 10000
#define ID_GUI_PLUGIN2_MESSAGE_TEXTCTRL 10001
#define SYMBOL_SAMPLEGUIPLUGINWINDOW2_STYLE wxTAB_TRAVERSAL
#define SYMBOL_SAMPLEGUIPLUGINWINDOW2_TITLE _("SampleGuiPluginWindow2")
#define SYMBOL_SAMPLEGUIPLUGINWINDOW2_IDNAME ID_SAMPLEGUIPLUGINWINDOW2
#define SYMBOL_SAMPLEGUIPLUGINWINDOW2_SIZE wxSize(400, 300)
#define SYMBOL_SAMPLEGUIPLUGINWINDOW2_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * SampleGuiPluginWindow2 class declaration
 */

class SampleGuiPluginWindow2: public wxGuiPluginWindowBase
{    
    DECLARE_DYNAMIC_CLASS( SampleGuiPluginWindow2 )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    SampleGuiPluginWindow2();
    SampleGuiPluginWindow2( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id = SYMBOL_SAMPLEGUIPLUGINWINDOW2_IDNAME, const wxPoint& pos = SYMBOL_SAMPLEGUIPLUGINWINDOW2_POSITION, const wxSize& size = SYMBOL_SAMPLEGUIPLUGINWINDOW2_SIZE, long style = SYMBOL_SAMPLEGUIPLUGINWINDOW2_STYLE );

    /// Creation
    bool Create( wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id = SYMBOL_SAMPLEGUIPLUGINWINDOW2_IDNAME, const wxPoint& pos = SYMBOL_SAMPLEGUIPLUGINWINDOW2_POSITION, const wxSize& size = SYMBOL_SAMPLEGUIPLUGINWINDOW2_SIZE, long style = SYMBOL_SAMPLEGUIPLUGINWINDOW2_STYLE );

    /// Destructor
    ~SampleGuiPluginWindow2();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin SampleGuiPluginWindow2 event handler declarations

    /// wxEVT_DESTROY event handler for ID_SAMPLEGUIPLUGINWINDOW2
    void OnDestroy( wxWindowDestroyEvent& event );

////@end SampleGuiPluginWindow2 event handler declarations
	void OnInteropMessageReceived(wxCommandEvent & event);

////@begin SampleGuiPluginWindow2 member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end SampleGuiPluginWindow2 member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin SampleGuiPluginWindow2 member variables
    wxTextCtrl* m_MessageTextCtrl;
////@end SampleGuiPluginWindow2 member variables
};

#endif
    // _SAMPLEGUIPLUGINWINDOW2_H_
