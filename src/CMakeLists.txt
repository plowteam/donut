set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE DONUT_SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp")
file(GLOB_RECURSE DONUT_HEADERS "${CMAKE_CURRENT_LIST_DIR}/*.h")

# force glm left handedness to be like simsons
add_definitions(-DGLM_FORCE_LEFT_HANDED)

if (WIN32)
    # Suppress WinMain(), provided by SDL
    add_definitions(-DSDL_MAIN_HANDLED)
    # Get rid of useless crud from windows.h
	add_definitions(-DNOMINMAX -DWIN32_LEAN_AND_MEAN)
	# disable CRT warnings on windows cause they're annoying as shit and we use C functions everywhere
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)
	# fast FP
	add_definitions(/fp:fast)

	set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SAFESEH:NO")
	set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${CMAKE_EXE_LINKER_FLAGS_MINSIZEREL} /SAFESEH:NO")
	set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /SAFESEH:NO")
	set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} /SAFESEH:NO")
endif()

# disable shite warnings
if (MSVC)
	add_compile_options(/wd4005) # macro redefinition https://docs.microsoft.com/en-us/visualstudio/code-quality/c4005
	add_compile_options(/wd26451) # arithmetic overflow https://docs.microsoft.com/en-us/visualstudio/code-quality/c26451
endif()

add_executable(${PROJECT_NAME} ${DONUT_SOURCES} ${DONUT_HEADERS})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 glm glad imgui)

if (BULLET_FOUND)
	target_include_directories(${PROJECT_NAME} PRIVATE ${BULLET_INCLUDE_DIR})

	target_link_libraries(${PROJECT_NAME} PRIVATE
		debug ${BULLET_COLLISION_LIBRARY_DEBUG} optimized ${BULLET_COLLISION_LIBRARY}
		debug ${BULLET_DYNAMICS_LIBRARY_DEBUG} optimized ${BULLET_DYNAMICS_LIBRARY}
		debug ${BULLET_MATH_LIBRARY_DEBUG} optimized ${BULLET_MATH_LIBRARY})
endif()


if (WIN32)
	if (USE_DEBUG_CONSOLE)
		set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:CONSOLE")
		set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:CONSOLE")
		set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_DEBUG "_CONSOLE")
	else (USE_DEBUG_CONSOLE)
		# Turn off debug console, debug output will be written to visual studio output instead
		set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_DEBUG "/SUBSYSTEM:WINDOWS")
		set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELWITHDEBINFO "/SUBSYSTEM:WINDOWS")
	endif()

	# Release builds don't use the debug console
    set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS")
    set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_DEFINITIONS_RELEASE "_WINDOWS")
	set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS_MINSIZEREL "/SUBSYSTEM:WINDOWS")
endif (WIN32)

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${DONUT_SOURCES} ${DONUT_HEADERS})

# copy sdl2.dll
if (MSVC)
	function(windows_copy_files TARGET SOURCE_DIR DEST_DIR)
		string(REPLACE "/" "\\\\" SOURCE_DIR ${SOURCE_DIR})
		string(REPLACE "/" "\\\\" DEST_DIR ${DEST_DIR})
		add_custom_command(TARGET ${TARGET} POST_BUILD
			COMMAND if not exist ${DEST_DIR} mkdir ${DEST_DIR} 2> nul
			COMMAND robocopy ${SOURCE_DIR} ${DEST_DIR} ${ARGN} /NJH /NJS /NDL /NFL /NC /NS /NP || cmd /c "exit /b 0"
		)
	endfunction()

    windows_copy_files(${PROJECT_NAME} ${SDL2_DLL_DIR} "${CMAKE_BINARY_DIR}/bin/$<CONFIG>/" SDL2.dll)
endif()