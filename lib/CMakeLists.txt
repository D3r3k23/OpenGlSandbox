set(BUILD_SHARED_LIBS OFF)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE glm)

add_subdirectory(glfw)
target_compile_definitions(glfw INTERFACE GLFW_INCLUDE_NONE) # Don't need GLFW to include OpenGL header

add_subdirectory(spdlog)

add_subdirectory(glad)
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
