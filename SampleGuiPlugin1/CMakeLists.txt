set (SRCS
	SampleGuiPlugin1.cpp
	SampleGuiPlugin1Exports.cpp)
set (HEADERS
	SampleGuiPlugin1.h)
	
set(LIBRARY_NAME SampleGuiPlugin1)

if(WIN32)
	set(SRCS ${SRCS} ${LIBRARY_NAME}.def)
	set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};/D_USRDLL;/D__STDC_CONSTANT_MACROS)
	set(LINK_DIRECTORIES 
		${PROJECT_ROOT_DIR}/wxGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX}/$(ConfigurationName))
	set(DEMO_LIBS wxGuiPluginBase.lib)
endif(WIN32)
if(LINUX)
	set(DEMO_LIBS wxGuiPluginBase)
	SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
	SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
	SET(CMAKE_INSTALL_RPATH ".:./../../")
endif(LINUX)

set(SRCS ${SRCS} ${HEADERS} 
	${PROJECT_ROOT_DIR}/include/stdwx.h 
	${PROJECT_ROOT_DIR}/include/stdwx.cpp)

add_definitions(${PREPROCESSOR_DEFINITIONS})

include_directories(${INCLUDE_DIRECTORIES} ${BASE_INCLUDE_DIRECTORIES} 
	${PROJECT_ROOT_DIR}/wxGuiPluginBase)
	
link_directories(${LINK_DIRECTORIES})

add_library(${LIBRARY_NAME} SHARED ${SRCS})

set(DLL_DIR bin)
if(LINUX)
	set(TARGET_LOCATION ${PROJECT_SOURCE_DIR}/${DLL_DIR}${LIB_SUFFIX}/plugins/gui)
else(LINUX)
	set(TARGET_LOCATION ${PROJECT_SOURCE_DIR}/${DLL_DIR}/${CMAKE_CFG_INTDIR}/plugins/gui)
	get_target_property(RESULT_FULL_PATH ${LIBRARY_NAME} LOCATION)
	get_filename_component(RESULT_FILE_NAME ${RESULT_FULL_PATH} NAME)
endif(LINUX)
set_target_properties(${LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_LOCATION})

target_link_libraries(${LIBRARY_NAME} ${DEMO_LIBS} ${wxWidgets_LIBRARIES})

add_dependencies(${LIBRARY_NAME} wxGuiPluginBase)

set_precompiled_header(${LIBRARY_NAME} ${PROJECT_ROOT_DIR}/include/stdwx.h ${PROJECT_ROOT_DIR}/include/stdwx.cpp)

if(LINUX)
	add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_LOCATION}
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${LIBRARY_NAME}> ${TARGET_LOCATION}/${RESULT_FILE_NAME}
	)
endif(LINUX)
