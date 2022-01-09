#ifndef UTIL_HPP
#define UTIL_HPP

#include <glad/glad.h>

void GLAPI gl_message_handler(GLenum source, GLenum type, GLuint id,
        GLenum severity, GLsizei length, const GLchar* msg, const void* userParam);

#endif // UTIL_HPP
