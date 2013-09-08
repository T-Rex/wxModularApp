/////////////////////////////////////////////////////////////////////////////
// Name:        MainFrame.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     02/08/2013 21:20:05
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _MAINFRAME_H_
#define _MAINFRAME_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/aui/framemanager.h"
#include "wx/frame.h"
#include "wx/statusbr.h"
#include "wx/aui/auibook.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
class wxAuiNotebook;
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
#define SYMBOL_MAINFRAME_STYLE wxCAPTION|wxRESIZE_BORDER|wxSYSTEM_MENU|wxCLOSE_BOX
#define SYMBOL_MAINFRAME_TITLE _("MainFrame")
#define SYMBOL_MAINFRAME_IDNAME ID_MAINFRAME
#define SYMBOL_MAINFRAME_SIZE wxSize(600, 450)
#define SYMBOL_MAINFRAME_POSITION wxDefaultPosition
////@end control identifiers


/*!
 * MainFrame class declaration
 */

class MainFrame: public wxFrame
{    
    DECLARE_CLASS( MainFrame )
    DECLARE_EVENT_TABLE()

public:
    /// Constructors
    MainFrame();
    MainFrame( wxWindow* parent, wxWindowID id = SYMBOL_MAINFRAME_IDNAME, const wxString& caption = SYMBOL_MAINFRAME_TITLE, const wxPoint& pos = SYMBOL_MAINFRAME_POSITION, const wxSize& size = SYMBOL_MAINFRAME_SIZE, long style = SYMBOL_MAINFRAME_STYLE );

    bool Create( wxWindow* parent, wxWindowID id = SYMBOL_MAINFRAME_IDNAME, const wxString& caption = SYMBOL_MAINFRAME_TITLE, const wxPoint& pos = SYMBOL_MAINFRAME_POSITION, const wxSize& size = SYMBOL_MAINFRAME_SIZE, long style = SYMBOL_MAINFRAME_STYLE );

    /// Destructor
    ~MainFrame();

    /// Initialises member variables
    void Init();

    /// Creates the controls and sizers
    void CreateControls();

////@begin MainFrame event handler declarations

////@end MainFrame event handler declarations

////@begin MainFrame member function declarations

    /// Returns the AUI manager object
    wxAuiManager& GetAuiManager() { return m_auiManager; }

    /// Retrieves bitmap resources
    wxBitmap GetBitmapResource( const wxString& name );

    /// Retrieves icon resources
    wxIcon GetIconResource( const wxString& name );
////@end MainFrame member function declarations

    /// Should we show tooltips?
    static bool ShowToolTips();

////@begin MainFrame member variables
    wxAuiManager m_auiManager;
    wxAuiNotebook* m_Notebook;
    /// Control identifiers
    enum {
        ID_MAINFRAME = 10000,
        ID_STATUSBAR = 10001,
        ID_AUINOTEBOOK = 10003
    };
////@end MainFrame member variables
};

#endif
    // _MAINFRAME_H_
