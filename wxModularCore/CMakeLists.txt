set (SRCS
	wxModularCore.cpp
	wxModularCoreSettings.cpp)
set (HEADERS
	wxModularCore.h
	wxModularCoreSettings.h)
	
set(LIBRARY_NAME wxModularCore)

if(WIN32)
	set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};/D__STDC_CONSTANT_MACROS)
endif(WIN32)

set(SRCS ${SRCS} ${HEADERS} 
	${PROJECT_ROOT_DIR}/include/stdwx.h 
	${PROJECT_ROOT_DIR}/include/stdwx.cpp)

add_definitions(${PREPROCESSOR_DEFINITIONS})

include_directories(${INCLUDE_DIRECTORIES} ${BASE_INCLUDE_DIRECTORIES} 
	${PROJECT_ROOT_DIR}/wxNonGuiPluginBase
	${PROJECT_ROOT_DIR}/wxGuiPluginBase)
	
link_directories(${LINK_DIRECTORIES})

add_library(${LIBRARY_NAME} STATIC ${SRCS})

set(DLL_DIR bin)
set(TARGET_LOCATION ${PROJECT_SOURCE_DIR}/${DLL_DIR}/${CMAKE_CFG_INTDIR})
set_target_properties(${LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_LOCATION})

add_dependencies(${LIBRARY_NAME} wxNonGuiPluginBase wxGuiPluginBase)

set_precompiled_header(${LIBRARY_NAME} ${PROJECT_ROOT_DIR}/include/stdwx.h ${PROJECT_ROOT_DIR}/include/stdwx.cpp)