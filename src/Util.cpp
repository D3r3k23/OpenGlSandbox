#include "Util.hpp"

#include <spdlog/spdlog.h>

#include <fstream>
#include <sstream>

std::string read_file(const std::filesystem::path& path)
{
    if (std::filesystem::is_regular_file(path))
    {
        std::ifstream file(path);
        std::stringstream contents;
        contents << file.rdbuf();
        return contents.str();
    }
    else
        return "";
}

void APIENTRY gl_message_handler(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* msg, const void* userParam)
{
    if (id == 131169 || id == 131185 || id == 131218 || 131204)
        return;

    const char* sourceStr = [source]{
        switch (source)
        {
            case GL_DEBUG_SOURCE_API             : return "API";
            case GL_DEBUG_SOURCE_WINDOW_SYSTEM   : return "window system";
            case GL_DEBUG_SOURCE_SHADER_COMPILER : return "shader compiler";
            case GL_DEBUG_SOURCE_THIRD_PARTY     : return "third party";
            case GL_DEBUG_SOURCE_APPLICATION     : return "application";
            case GL_DEBUG_SOURCE_OTHER           : return "other";
            default                              : return "unknown";
        }
    }();
    const char* typeStr = [type]{
        switch (type)
        {
            case GL_DEBUG_TYPE_ERROR               : return "error";
            case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR : return "deprecated behavior";
            case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR  : return "undefined behavior";
            case GL_DEBUG_TYPE_PORTABILITY         : return "portability";
            case GL_DEBUG_TYPE_PERFORMANCE         : return "performance";
            case GL_DEBUG_TYPE_MARKER              : return "marker";
            case GL_DEBUG_TYPE_PUSH_GROUP          : return "push group";
            case GL_DEBUG_TYPE_POP_GROUP           : return "pop group";
            case GL_DEBUG_TYPE_OTHER               : return "other";
            default                                : return "unknown";
        }
    }();
    switch (severity)
    {
        case GL_DEBUG_SEVERITY_HIGH:
            spdlog::error("[OpenGL error] source: {0} | type: {1} | msg: {2}", sourceStr, typeStr, msg);
            break;
        case GL_DEBUG_SEVERITY_MEDIUM:
            spdlog::warn("[OpenGL error] source: {0} | type: {1} | msg: {2}", sourceStr, typeStr, msg);
            break;
        case GL_DEBUG_SEVERITY_LOW:
            spdlog::info("[OpenGL error] source: {0} | type: {1} | msg: {2}", sourceStr, typeStr, msg);
            break;
        case GL_DEBUG_SEVERITY_NOTIFICATION:
            spdlog::info("[OpenGL message] source: {0} | type: {1} | msg: {2}", sourceStr, typeStr, msg);
            break;
        default:
            spdlog::warn("[OpenGL message] severity: {0} | source: {1} | type: {2} | msg: {3}", severity, sourceStr, typeStr, msg);
    }
}
