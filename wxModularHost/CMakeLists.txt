set(SRCS
	MainFrame.cpp
	wxModularHostApp.cpp)
set(HEADERS
	MainFrame.h
	wxModularHostApp.h)
	
set(INCLUDE_DIRECTORIES ${BASE_INCLUDE_DIRECTORIES})

if(WIN32)
	set(SRCS ${SRCS} wxModularHost.rc)
	set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};
		/D_USRDLL;
		/DwxUSE_NO_MANIFEST=1;
		/D__STDC_CONSTANT_MACROS)
endif(WIN32)

set(LIBS ${wxWidgets_LIBRARIES})

set(EXECUTABLE_NAME wxModularHost)

add_definitions(${PREPROCESSOR_DEFINITIONS})
include_directories(${INCLUDE_DIRECTORIES})

if(WIN32)
	set(EXECUTABLE_TYPE WIN32)
endif(WIN32)
if(APPLE)
	set(MACOSX_BUNDLE YES)
	set(EXECUTABLE_TYPE MACOSX_BUNDLE)
endif(APPLE)
if(LINUX)
	set(EXECUTABLE_TYPE "")
endif(LINUX)

set(PROJECT_FILES ${SRCS} ${HFILES})
add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_TYPE} ${PROJECT_FILES})

set(EXE_DIR bin)
set(TARGET_LOCATION ${PROJECT_SOURCE_DIR}/${EXE_DIR}${LIB_SUFFIX})
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_LOCATION})
target_link_libraries(${EXECUTABLE_NAME} ${LIBS})