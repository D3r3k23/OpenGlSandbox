cmake_minimum_required(VERSION 3.19)

project(OpenGlSandbox)

add_executable(OpenGlSandbox)
add_subdirectory(src)
add_subdirectory(lib)

set_target_properties(OpenGlSandbox
  PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)

set_target_properties(OpenGlSandbox
  PROPERTIES
    OUTPUT_NAME App
)
