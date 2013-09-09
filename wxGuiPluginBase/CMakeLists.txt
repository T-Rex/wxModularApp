set (SRCS
	wxGuiPluginBase.cpp)
set (HEADERS
	Declarations.h
	wxGuiPluginBase.h)
	
set(LIBRARY_NAME wxGuiPluginBase)

if(WIN32)
	# Only for Windows:
	# we add additional preprocessor definitons
	set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};
		/D_USRDLL;/DDEMO_PLUGIN_EXPORTS;/D__STDC_CONSTANT_MACROS)
endif(WIN32)

# Add 2 files for precompiled headers
set(SRCS ${SRCS} ${HEADERS} 
	${PROJECT_ROOT_DIR}/include/stdwx.h 
	${PROJECT_ROOT_DIR}/include/stdwx.cpp)

# Set preprocessor definitions
add_definitions(${PREPROCESSOR_DEFINITIONS})
# Set include directories
include_directories(${INCLUDE_DIRECTORIES} ${BASE_INCLUDE_DIRECTORIES})
# Set library search paths
link_directories(${LINK_DIRECTORIES})
# Setup the project name and assign the source files for this project
add_library(${LIBRARY_NAME} SHARED ${SRCS})

#Setup the output folder
set(DLL_DIR bin)
set(TARGET_LOCATION ${PROJECT_SOURCE_DIR}/${DLL_DIR}${LIB_SUFFIX})
if(LINUX)
	get_target_property(RESULT_FULL_PATH ${LIBRARY_NAME} LOCATION)
	get_filename_component(RESULT_FILE_NAME ${RESULT_FULL_PATH} NAME)
endif(LINUX)
set_target_properties(${LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_LOCATION})

# Set additional dependencies
target_link_libraries(${LIBRARY_NAME} ${wxWidgets_LIBRARIES})

# Setup precompiled headers
set_precompiled_header(${LIBRARY_NAME} ${PROJECT_ROOT_DIR}/include/stdwx.h ${PROJECT_ROOT_DIR}/include/stdwx.cpp)

if(LINUX)
	add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${LIBRARY_NAME}> ${TARGET_LOCATION}/${RESULT_FILE_NAME}
	)
endif(LINUX)
