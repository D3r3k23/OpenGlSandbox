set(BUILD_SHARED_LIBS OFF)

add_library(glm INTERFACE)
target_include_directories(glm INTERFACE glm)

message("Configuring GLFW")
set(GLFW_BUILD_DOCS OFF)
add_subdirectory(glfw)
target_compile_definitions(glfw INTERFACE GLFW_INCLUDE_NONE) # Don't need GLFW to include OpenGL header

message("Configuring spdlog")
set(SPDLOG_FMT_EXTERNAL ON)
add_subdirectory(spdlog)

add_subdirectory(glad)
add_subdirectory(stb)

target_link_libraries(OpenGlSandbox
  PUBLIC
    glad
    glfw
    glm
    spdlog
    stb_image
)
