set (SRCS
	SampleGuiPlugin2.cpp
	SampleGuiPlugin2Exports.cpp
	SampleGuiPluginWindow2.cpp)
set (HEADERS
	SampleGuiPlugin2.h
	SampleGuiPluginWindow2.h)
	
set(LIBRARY_NAME SampleGuiPlugin2)

if(WIN32)
	set(SRCS ${SRCS} ${LIBRARY_NAME}.def)
	set(PREPROCESSOR_DEFINITIONS ${PREPROCESSOR_DEFINITIONS};/D_USRDLL;/D__STDC_CONSTANT_MACROS)
	set(LINK_DIRECTORIES 
		${PROJECT_ROOT_DIR}/wxGuiPluginBase/${OS_BASE_NAME}${LIB_SUFFIX}/$(ConfigurationName))
	set(DEMO_LIBS wxGuiPluginBase.lib)
endif(WIN32)
if(LINUX OR APPLE)
	set(DEMO_LIBS wxGuiPluginBase)
	SET(CMAKE_SKIP_BUILD_RPATH  FALSE)
	SET(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE) 
	SET(CMAKE_INSTALL_RPATH ".:./../../")
endif(LINUX OR APPLE)

set(SRCS ${SRCS} ${HEADERS} 
	${PROJECT_ROOT_DIR}/include/stdwx.h 
	${PROJECT_ROOT_DIR}/include/stdwx.cpp)

add_definitions(${PREPROCESSOR_DEFINITIONS})

include_directories(${INCLUDE_DIRECTORIES} ${BASE_INCLUDE_DIRECTORIES} 
	${PROJECT_ROOT_DIR}/wxGuiPluginBase)
	
link_directories(${LINK_DIRECTORIES})

add_library(${LIBRARY_NAME} SHARED ${SRCS})

set(DLL_DIR bin)
if(APPLE)
	set(BUNDLE_SUBFOLDER 
		"/$(CONFIGURATION)/${PROJECT_NAME}.app/Contents/PlugIns")
endif(APPLE)
if(WIN32)
        set(TARGET_LOCATION
                ${PROJECT_SOURCE_DIR}/${DLL_DIR}${LIB_SUFFIX}/${CMAKE_CFG_INTDIR}/plugins/gui)
elseif (LINUX)
        set(TARGET_LOCATION
                ${PROJECT_SOURCE_DIR}/${DLL_DIR}${LIB_SUFFIX}${BUNDLE_SUBFOLDER}/plugins/gui)
else()
        set(TARGET_LOCATION
                ${PROJECT_SOURCE_DIR}/${DLL_DIR}${LIB_SUFFIX}${BUNDLE_SUBFOLDER}/gui)
endif(WIN32)
if(LINUX OR APPLE)
	get_target_property(RESULT_FULL_PATH ${LIBRARY_NAME} LOCATION)
	get_filename_component(RESULT_FILE_NAME ${RESULT_FULL_PATH} NAME)
endif(LINUX OR APPLE)

set_target_properties(${LIBRARY_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${TARGET_LOCATION})

target_link_libraries(${LIBRARY_NAME} ${DEMO_LIBS} ${wxWidgets_LIBRARIES})

add_dependencies(${LIBRARY_NAME} wxGuiPluginBase)

set_precompiled_header(${LIBRARY_NAME} ${PROJECT_ROOT_DIR}/include/stdwx.h ${PROJECT_ROOT_DIR}/include/stdwx.cpp)

if(APPLE)
	FOREACH(DEP_LIB ${DEMO_LIBS})
		get_filename_component(ABS_ROOT_DIR ${PROJECT_ROOT_DIR} ABSOLUTE)
		set(LIBNAME_FULL "${ABS_ROOT_DIR}/${DEP_LIB}/${OS_BASE_NAME}${LIB_SUFFIX}/$(CONFIGURATION)/lib${DEP_LIB}.dylib")
                add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
                	COMMAND install_name_tool -change "${LIBNAME_FULL}" "@executable_path/../Frameworks/lib${DEP_LIB}.dylib" $<TARGET_FILE:${LIBRARY_NAME}>)
        ENDFOREACH(DEP_LIB)
endif(APPLE)
if(LINUX OR APPLE)
	add_custom_command(TARGET ${LIBRARY_NAME} POST_BUILD
		COMMAND ${CMAKE_COMMAND} -E make_directory ${TARGET_LOCATION}
		COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${LIBRARY_NAME}> ${TARGET_LOCATION}/${RESULT_FILE_NAME}
	)
endif(LINUX OR APPLE)
