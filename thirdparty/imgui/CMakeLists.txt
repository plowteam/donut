add_library(imgui STATIC
  imconfig.h
  imgui.h
  imgui_internal.h
  imstb_rectpack.h
  imstb_textedit.h
  imstb_truetype.h

  imgui.cpp
  imgui_demo.cpp
  imgui_draw.cpp
  imgui_widgets.cpp

  imgui_impl_opengl3.cpp
  imgui_impl_opengl3.h
  imgui_impl_sdl.cpp
  imgui_impl_sdl.h
)

add_definitions(-DIMGUI_IMPL_OPENGL_LOADER_GLAD)

target_link_libraries(imgui PRIVATE glad ${SDL2_LIBRARY})
target_include_directories(imgui PUBLIC "")
target_include_directories(imgui PRIVATE ${SDL2_INCLUDE_DIR})
