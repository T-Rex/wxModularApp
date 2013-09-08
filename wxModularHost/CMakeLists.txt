set(SRCS
	MainFrame.cpp
	SampleModularCore.cpp
	wxModularHostApp.cpp)
set(HEADERS
	MainFrame.h
	SampleModularCore.h
	wxModularHostApp.h)
	
set(INCLUDE_DIRECTORIES ${BASE_INCLUDE_DIRECTORIES}
	${PROJECT_ROOT_DIR}/wxModularCore
	${PROJECT_ROOT_DIR}/wxNonGuiPluginBase
	${PROJECT_ROOT_DIR}/wxGuiPluginBase)

if(WIN32)
	set(SRCS ${SRCS} wxModularHost.rc)
	set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};
		/D_USRDLL;
		/DwxUSE_NO_MANIFEST=1;
		/D__STDC_CONSTANT_MACROS)
	set(LINK_DIRECTORIES 
		${PROJECT_ROOT_DIR}/wxNonGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX}/$(ConfigurationName)
		${PROJECT_ROOT_DIR}/wxGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX}/$(ConfigurationName)
		${PROJECT_ROOT_DIR}/wxModularCore/${OS_BASE_NAME}${LIB_SUFFIX}/$(ConfigurationName))
	set(DEMO_LIBS wxModularCore.lib wxNonGuiPluginBase.lib wxGuiPluginBase.lib)
endif(WIN32)
if(LINUX)
	set(LINK_DIRECTORIES 
		${PROJECT_ROOT_DIR}/wxNonGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX}
		${PROJECT_ROOT_DIR}/wxGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX}
		${PROJECT_ROOT_DIR}/wxModularCore/${OS_BASE_NAME}${LIB_SUFFIX})
	set(DEMO_LIBS wxModularCore wxNonGuiPluginBase wxGuiPluginBase)
endif(LINUX)

set(LIBS ${DEMO_LIBS} ${wxWidgets_LIBRARIES})

set(EXECUTABLE_NAME wxModularHost)

add_definitions(${PREPROCESSOR_DEFINITIONS})
include_directories(${INCLUDE_DIRECTORIES} ${BASE_INCLUDE_DIRECTORIES})
link_directories(${LINK_DIRECTORIES})

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

set(SRCS ${SRCS} ${HEADERS} 
	${PROJECT_ROOT_DIR}/include/stdwx.h 
	${PROJECT_ROOT_DIR}/include/stdwx.cpp)

set(PROJECT_FILES ${SRCS})
add_executable(${EXECUTABLE_NAME} ${EXECUTABLE_TYPE} ${PROJECT_FILES})

set(EXE_DIR bin)
set(TARGET_LOCATION ${PROJECT_SOURCE_DIR}/${EXE_DIR}${LIB_SUFFIX})
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_LOCATION})
target_link_libraries(${EXECUTABLE_NAME} ${LIBS})

add_dependencies(${EXECUTABLE_NAME} wxModularCore)

set_precompiled_header(${EXECUTABLE_NAME} 
	${PROJECT_ROOT_DIR}/include/stdwx.h 
	${PROJECT_ROOT_DIR}/include/stdwx.cpp)
