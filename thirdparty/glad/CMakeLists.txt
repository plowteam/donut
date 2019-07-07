add_library(glad STATIC
    src/glad.c
    include/KHR/khrplatform.h
    include/glad/glad.h
)

target_include_directories(glad PUBLIC "include/")

if ("${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
    target_link_libraries(glad PRIVATE dl)
endif()
