set(CMAKE_INCLUDE_CURRENT_DIR ON)

file(GLOB_RECURSE DONUT_SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/*.c")
file(GLOB_RECURSE DONUT_C_SOURCES "${CMAKE_CURRENT_LIST_DIR}/*.c")
file(GLOB_RECURSE DONUT_HEADERS "${CMAKE_CURRENT_LIST_DIR}/*.h")

set(DONUT_RC ${CMAKE_SOURCE_DIR}/assets/windows/donut.rc)
set(DONUT_MANIFEST ${CMAKE_SOURCE_DIR}/assets/windows/donut.exe.manifest)

# imgui use GLAD loader
add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

if (WIN32)
    # Suppress WinMain(), provided by SDL
    add_definitions(-DSDL_MAIN_HANDLED)
    # Get rid of useless crud from windows.h
	add_definitions(-DNOMINMAX -DWIN32_LEAN_AND_MEAN)
	# disable CRT warnings on windows cause they're annoying as shit
	add_definitions(-D_CRT_SECURE_NO_WARNINGS)

	# some MSVC compiler options
	if(MSVC)
		# /W4                 - Level 4 warnings
		# /MP                 - Multi-threaded compilation
		# /permissive-        - Enables stricter C++ standards conformance checks
		add_compile_options(/W4 /MP /permissive-)

		# fast FP
		add_definitions(/fp:fast)

		set(CMAKE_EXE_LINKER_FLAGS_DEBUG "${CMAKE_EXE_LINKER_FLAGS_DEBUG} /SAFESEH:NO")
		set(CMAKE_EXE_LINKER_FLAGS_MINSIZEREL "${CMAKE_EXE_LINKER_FLAGS_MINSIZEREL} /SAFESEH:NO")
		set(CMAKE_EXE_LINKER_FLAGS_RELEASE "${CMAKE_EXE_LINKER_FLAGS_RELEASE} /SAFESEH:NO")
		set(CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO "${CMAKE_EXE_LINKER_FLAGS_RELWITHDEBINFO} /SAFESEH:NO")

		# disable shite warnings
		add_compile_options(/wd4005) # macro redefinition https://docs.microsoft.com/en-us/visualstudio/code-quality/c4005
		add_compile_options(/wd26451) # arithmetic overflow https://docs.microsoft.com/en-us/visualstudio/code-quality/c26451
	endif()
endif()

add_executable(${PROJECT_NAME} ${DONUT_SOURCES} ${DONUT_HEADERS} ${DONUT_RC} ${DONUT_MANIFEST})
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)

target_link_libraries(${PROJECT_NAME}
	PRIVATE
		SDL2::SDL2
		Bullet::Bullet
		OpenAL::OpenAL
		fmt::fmt
	)

# configure filesystem for slightly older compilers
if (_CXX_FILESYSTEM_HAVE_HEADER)
	target_compile_definitions(${PROJECT_NAME} PRIVATE DONUT_HAS_FILESYSTEM)
elseif (_CXX_FILESYSTEM_HAVE_EXPERIMENTAL_HEADER)
	target_compile_definitions(${PROJECT_NAME} PRIVATE DONUT_HAS_FILESYSTEM_EXPERIMENTAL)
endif()

source_group(TREE ${CMAKE_CURRENT_LIST_DIR} FILES ${DONUT_SOURCES} ${DONUT_HEADERS})

# copy SDL2.dll & soft_oal.dll
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
    windows_copy_files(${PROJECT_NAME} ${OPENAL_DLL_DIR} "${CMAKE_BINARY_DIR}/bin/$<CONFIG>/" soft_oal.dll)
endif()
