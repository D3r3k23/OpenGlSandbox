add_library(imgui)

target_sources(imgui
  PRIVATE
    imgui/imgui.cpp
    imgui/imgui_draw.cpp
    imgui/imgui_tables.cpp
    imgui/imgui_widgets.cpp
    imgui/imgui_demo.cpp

    imgui/backends/imgui_impl_glfw.cpp
    imgui/backends/imgui_impl_opengl3.cpp
)

target_include_directories(imgui
  PUBLIC
    imgui
    imgui/backends
)

target_link_libraries(imgui
  PUBLIC
    glad
    glfw
)
