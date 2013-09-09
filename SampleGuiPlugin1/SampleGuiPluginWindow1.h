/////////////////////////////////////////////////////////////////////////////
// Name:        SampleGuiPluginWindow1.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     10/09/2013 00:01:49
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _SAMPLEGUIPLUGINWINDOW1_H_
#define _SAMPLEGUIPLUGINWINDOW1_H_


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
#define ID_SAMPLEGUIPLUGINWINDOW1 10000
#define ID_SAMPLE_TEXTCTRL 10001
#define ID_SEND_EVENT_BUTTON 10002
#define SYMBOL_SAMPLEGUIPLUGINWINDOW1_STYLE wxTAB_TRAVERSAL
#define SYMBOL_SAMPLEGUIPLUGINWINDOW1_TITLE _("SampleGuiPluginWindow1")
#define SYMBOL_SAMPLEGUIPLUGINWINDOW1_IDNAME ID_SAMPLEGUIPLUGINWINDOW1
#define SYMBOL_SAMPLEGUIPLUGINWINDOW1_SIZE wxSize(400, 300)
#define SYMBOL_SAMPLEGUIPLUGINWINDOW1_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * SampleGuiPluginWindow1 class declaration
 */

class SampleGuiPluginWindow1: public wxGuiPluginWindowBase
{    
    DECLARE_DYNAMIC_CLASS( SampleGuiPluginWindow1 )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    SampleGuiPluginWindow1();
    SampleGuiPluginWindow1(wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id = SYMBOL_SAMPLEGUIPLUGINWINDOW1_IDNAME, const wxPoint& pos = SYMBOL_SAMPLEGUIPLUGINWINDOW1_POSITION, const wxSize& size = SYMBOL_SAMPLEGUIPLUGINWINDOW1_SIZE, long style = SYMBOL_SAMPLEGUIPLUGINWINDOW1_STYLE );

    /// Creation
    bool Create(wxGuiPluginBase * plugin, wxWindow* parent, wxWindowID id = SYMBOL_SAMPLEGUIPLUGINWINDOW1_IDNAME, const wxPoint& pos = SYMBOL_SAMPLEGUIPLUGINWINDOW1_POSITION, const wxSize& size = SYMBOL_SAMPLEGUIPLUGINWINDOW1_SIZE, long style = SYMBOL_SAMPLEGUIPLUGINWINDOW1_STYLE );

    /// Destructor
    ~SampleGuiPluginWindow1();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin SampleGuiPluginWindow1 event handler declarations

    /// wxEVT_COMMAND_BUTTON_CLICKED event handler for ID_SEND_EVENT_BUTTON
    void OnSENDEVENTBUTTONClick( wxCommandEvent& event );

////@end SampleGuiPluginWindow1 event handler declarations

////@begin SampleGuiPluginWindow1 member function declarations

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end SampleGuiPluginWindow1 member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin SampleGuiPluginWindow1 member variables
    wxTextCtrl* m_SamppleTextCtrl;
////@end SampleGuiPluginWindow1 member variables
};

#endif
    // _SAMPLEGUIPLUGINWINDOW1_H_
