#ifndef UTIL_HPP
#define UTIL_HPP

#include <glad/glad.h>

#include <string>
#include <filesystem>

std::string read_file(std::string_view filename);

void APIENTRY gl_message_handler(GLenum source, GLenum type, GLuint id,
        GLenum severity, GLsizei length, const GLchar* msg, const void* userParam);

#endif // UTIL_HPP
