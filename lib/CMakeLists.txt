set(BUILD_SHARED_LIBS OFF)

add_subdirectory(glfw)
target_compile_definitions(glfw INTERFACE GLFW_INCLUDE_NONE)

add_subdirectory(glad)
add_subdirectory(glm)
add_subdirectory(imgui)
add_subdirectory(spdlog)
add_subdirectory(stb)

target_link_libraries(OpenGlSandbox
  PUBLIC
    glad
    glfw
    glm
    imgui
    spdlog
    stb_image
)
