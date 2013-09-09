/////////////////////////////////////////////////////////////////////////////
// Name:        wxGuiPluginWindowBase.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     09/09/2013 23:54:21
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXGUIPLUGINWINDOWBASE_H_
#define _WXGUIPLUGINWINDOWBASE_H_


/*!
 * Includes
 */

////@begin includes
////@end includes
#include "Declarations.h"

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxGuiPluginWindowBase;
////@end forward declarations
class wxGuiPluginBase;

/*!
 * Control identifiers
 */

////@begin control identifiers
#define ID_WXGUIPLUGINWINDOWBASE 10000
#define SYMBOL_WXGUIPLUGINWINDOWBASE_STYLE wxNO_BORDER|wxTAB_TRAVERSAL
#define SYMBOL_WXGUIPLUGINWINDOWBASE_IDNAME ID_WXGUIPLUGINWINDOWBASE
#define SYMBOL_WXGUIPLUGINWINDOWBASE_SIZE wxDefaultSize
#define SYMBOL_WXGUIPLUGINWINDOWBASE_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * wxGuiPluginWindowBase class declaration
 */

class DEMO_API wxGuiPluginWindowBase: public wxPanel
{    
    DECLARE_DYNAMIC_CLASS( wxGuiPluginWindowBase )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    wxGuiPluginWindowBase();
    wxGuiPluginWindowBase(wxGuiPluginBase * plugin, 
        wxWindow* parent, 
        wxWindowID id = ID_WXGUIPLUGINWINDOWBASE, 
        const wxPoint& pos = wxDefaultPosition, 
        const wxSize& size = wxDefaultSize, 
        long style = wxNO_BORDER|wxTAB_TRAVERSAL);

    /// Creation
    bool Create(wxGuiPluginBase * plugin, 
        wxWindow* parent, 
        wxWindowID id = ID_WXGUIPLUGINWINDOWBASE, 
        const wxPoint& pos = wxDefaultPosition, 
        const wxSize& size = wxDefaultSize, 
        long style = wxNO_BORDER|wxTAB_TRAVERSAL);

    /// Destructor
    ~wxGuiPluginWindowBase();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin wxGuiPluginWindowBase event handler declarations

////@end wxGuiPluginWindowBase event handler declarations

////@begin wxGuiPluginWindowBase member function declarations

    wxGuiPluginBase * GetPlugin() const { return m_Plugin ; }
    void SetPlugin(wxGuiPluginBase * value) { m_Plugin = value ; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end wxGuiPluginWindowBase member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin wxGuiPluginWindowBase member variables
    wxGuiPluginBase * m_Plugin;
////@end wxGuiPluginWindowBase member variables
};

#endif
    // _WXGUIPLUGINWINDOWBASE_H_
