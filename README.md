wxModularApp
============

Cross-Platform Modular Application (Main app + plugins) example for C++/wxWidgets

Requirements
------------
* Compiled shared (DLL Debug/DLL Release) version of wxWidgets. [SVN HEAD](http://svn.wxwidgets.org/svn/wx/wxWidgets/trunk) or official [2.9.x](http://svn.wxwidgets.org/svn/wx/wxWidgets/tags/WX_2_9_5/) release should work fine
* [CMake](http://www.cmake.org/) - required on all platforms. It is used for creating 
  * Visual Studio projects under Windows
  * Makefiles under Linux
  * XCode projects under OS X
* Under Windows %WXWIN% environment variable is required. Should point to wxWidgets source folder (e.g. C:\libs\wxWidgets-svn)
