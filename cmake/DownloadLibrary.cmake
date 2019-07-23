function(download_library remote_url lib_name prefix_var)
set(prefix "${CMAKE_BINARY_DIR}/thirdparty/${lib_name}")
if (NOT EXISTS "${prefix}")
    message(STATUS "Downloading binaries for ${lib_name}...")
    file(DOWNLOAD
        ${remote_url}
        "${CMAKE_BINARY_DIR}/thirdparty/${lib_name}.zip" SHOW_PROGRESS)
    execute_process(COMMAND ${CMAKE_COMMAND} -E tar xf "${CMAKE_BINARY_DIR}/thirdparty/${lib_name}.zip"
        WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/thirdparty")
endif()
message(STATUS "Using downloaded binaries at ${prefix}")
set(${prefix_var} "${prefix}" PARENT_SCOPE)
endfunction()