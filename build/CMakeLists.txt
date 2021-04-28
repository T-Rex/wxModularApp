cmake_minimum_required(VERSION 2.6.0)

include(PCHSupport.cmake)

# We will generate both Debug and Release project files at the same time
# for Windows and OS X
if(WIN32 OR APPLE)
	set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "" FORCE)
	set(LIB_SUFFIX "") 
endif(WIN32 OR APPLE)

# For Linux we will need to execute CMake twice in order to generate
# Debug and Release versions of Makefiles
if(UNIX AND NOT APPLE)
	set(LINUX ON)
	set(LIB_SUFFIX /${CMAKE_BUILD_TYPE}) 
endif(UNIX AND NOT APPLE)

set(PROJECT_NAME wxModularHost)
project(${PROJECT_NAME})

# If there are any additional CMake modules (e.g. module which searches 
# for OpenCV or for DirectShow libs), then CMake should start searching 
# for them in current folder
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

if(APPLE)
	set(OS_BASE_NAME Mac)
	set(CMAKE_OSX_SYSROOT "macosx10.8")	
endif(APPLE)
if(LINUX)
	set(OS_BASE_NAME Linux)
endif(LINUX)
if(WIN32)
	set(OS_BASE_NAME Win)
endif(WIN32)

# Here we specify the list of wxWidgets libs which we will use in our project
set(wxWidgets_USE_LIBS base core adv aui net gl xml propgrid html)

# Here we specify that we need DLL version of wxWidgets libs and dynamic CRT
# This is a MUST for applications with plugins. Both app and DLL plugin MUST
# use the same instance of wxWidgets and the same event loop.
set(BUILD_SHARED_LIBS 1)

# Find wxWidgets library on current PC
# You should have %WXWIN%  environment variable which should point to the
# directory where wxWidgets source code is placed.
# wxWidgets libs MUST be compiled for both Debug and Release versions
find_package(wxWidgets REQUIRED)


# For some reason CMake generates wrong list of definitions.
# Each item should start with /D but it does not.
# We need to fix that manually
set(wxWidgets_DEFINITIONS_TEMP)
foreach(DEFINITION ${wxWidgets_DEFINITIONS})
	
	if(NOT ${DEFINITION} MATCHES "/D.*")
		set(DEFINITION "/D${DEFINITION}")
	endif()
	set(wxWidgets_DEFINITIONS_TEMP ${wxWidgets_DEFINITIONS_TEMP} 
		${DEFINITION})
endforeach(${DEFINITION})
set(wxWidgets_DEFINITIONS ${wxWidgets_DEFINITIONS_TEMP})

# Here we add some definitions which prevent Visual Studio from 
# generating tons of warnings about unsecure function calls.
# See http://msdn.microsoft.com/en-us/library/ttcz0bys.aspx
if(WIN32)
	set(wxWidgets_DEFINITIONS ${wxWidgets_DEFINITIONS};
		/D_CRT_SECURE_NO_DEPRECATE;
		/D_CRT_NONSTDC_NO_DEPRECATE;
		/D_UNICODE)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MP /wd4996")
endif(WIN32)

# Since we are going to use wxWidgets in all subrojects,
# it's OK to create the variable which will contain 
# common preprocessor definitions. This variable will be 
# used in subprojects.
set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};
		${wxWidgets_DEFINITIONS})

# Variable which points to root folder of our source code
set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR}/..)

# If any ThirdParty libraries are going to be 
# used in our project then it would be better to put 
# them into separate subfolder. We will create 
# the variable which points to this subfolder.
set(THIRD_PARTY_DIR ${PROJECT_ROOT_DIR}/ThirdParty)

set(BASE_INCLUDE_DIRECTORIES ${PROJECT_ROOT_DIR}/include)

# Add wxWidgets include paths to the list of 
# include directories for all projects.
include_directories(${wxWidgets_INCLUDE_DIRS})

if(WIN32 OR LINUX)
	set(CMAKE_CXX_FLAGS_DEBUG 
		"${CMAKE_CXX_FLAGS_DEBUG}
		/D__WXDEBUG__=1" )
endif(WIN32 OR LINUX)

# Now we can include all our subprojects. 
# CMake will generate project files for them
add_subdirectory (../wxModularHost 
	../../wxModularHost/${OS_BASE_NAME}${LIB_SUFFIX})
add_subdirectory (../wxModularCore 
	../../wxModularCore/${OS_BASE_NAME}${LIB_SUFFIX})	

add_subdirectory (../wxNonGuiPluginBase 
	../../wxNonGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX})
add_subdirectory (../SampleNonGuiPlugin 
	../../SampleNonGuiPlugin/${OS_BASE_NAME}${LIB_SUFFIX})
	
add_subdirectory (../wxGuiPluginBase 
	../../wxGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX})
add_subdirectory (../SampleGuiPlugin1 
	../../SampleGuiPlugin1/${OS_BASE_NAME}${LIB_SUFFIX})
add_subdirectory (../SampleGuiPlugin2 
	../../SampleGuiPlugin2/${OS_BASE_NAME}${LIB_SUFFIX})
