/////////////////////////////////////////////////////////////////////////////
// Name:        wxModularHostApp.h
// Purpose:     
// Author:      Volodymyr (T-Rex) Triapichko
// Modified by: 
// Created:     02/08/2013 21:14:33
// RCS-ID:      
// Copyright:   Volodymyr (T-Rex) Triapichko, 2013
// Licence:     
/////////////////////////////////////////////////////////////////////////////

#ifndef _WXMODULARHOSTAPP_H_
#define _WXMODULARHOSTAPP_H_


/*!
 * Includes
 */

////@begin includes
#include "wx/image.h"
#include "MainFrame.h"
////@end includes

/*!
 * Forward declarations
 */

////@begin forward declarations
////@end forward declarations

/*!
 * Control identifiers
 */

////@begin control identifiers
////@end control identifiers

/*!
 * wxModularHostApp class declaration
 */

class wxModularHostApp: public wxApp
{    
    DECLARE_CLASS( wxModularHostApp )
    DECLARE_EVENT_TABLE()

public:
    /// Constructor
    wxModularHostApp();

    void Init();

    /// Initialises the application
    virtual bool OnInit();

    /// Called on exit
    virtual int OnExit();

////@begin wxModularHostApp event handler declarations

////@end wxModularHostApp event handler declarations

////@begin wxModularHostApp member function declarations

////@end wxModularHostApp member function declarations

////@begin wxModularHostApp member variables
////@end wxModularHostApp member variables
};

/*!
 * Application instance declaration 
 */

////@begin declare app
DECLARE_APP(wxModularHostApp)
////@end declare app

#endif
    // _WXMODULARHOSTAPP_H_
