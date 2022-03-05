#include "Sandbox.hpp"

#include "Util.hpp"

#include <spdlog/spdlog.h>

#include <vector>

Sandbox::Sandbox(void)
{
    {
        spdlog::info("Creating vertex shader");
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        std::string vertexShaderSrc = read_file("assets/shaders/flat_color_vertex_shader.glsl");
        compile_shader(vertexShader, vertexShaderSrc);
    }{
        spdlog::info("Creating fragment shader");
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        std::string fragmentShaderSrc = read_file("assets/shaders/flat_color_fragment_shader.glsl");
        compile_shader(fragmentShader, fragmentShaderSrc);
    }{
        spdlog::info("Creating shader program");
        shaderProgram = glCreateProgram();
        link_shader_program(shaderProgram, {vertexShader, fragmentShader});
    }{
        spdlog::info("Creating cube vertex buffer");
        glCreateBuffers(1, &cubeVertexBuffer);
    }{
        spdlog::info("Creating cube index buffer");
        glCreateBuffers(1, &cubeIndexBuffer);
    }{
        spdlog::info("Creating cube vertex array");
        glGenVertexArrays(1, &cubeVertexArray);
    }
}

Sandbox::~Sandbox(void)
{
    glDeleteBuffers(1, &cubeVertexBuffer);
    glDeleteBuffers(1, &cubeIndexBuffer);
    glDeleteVertexArrays(1, &cubeVertexArray);

    glDeleteProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Sandbox::render(void)
{

}

void Sandbox::compile_shader(GLuint shader, std::string_view src)
{
    const char* raw_source = src.data();
    const int length = src.size();
    glShaderSource(shader, 1, &raw_source, &length);

    glCompileShader(shader);
    GLint success = 0;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        GLint shaderLogLength = 0;
        glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &shaderLogLength);

        std::vector<GLchar> shaderLog(shaderLogLength);
        glGetShaderInfoLog(shader, shaderLogLength, nullptr, shaderLog.data());
        shaderLog[shaderLogLength - 1] = '\0';

        spdlog::error("Shader compilation failed: {}", shaderLog.data());
    }
}

void Sandbox::link_shader_program(GLuint program, std::initializer_list<GLuint> shaders)
{
    for (auto shader : shaders)
        glAttachShader(program, shader);

    glLinkProgram(program);
    GLint success = 0;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (!success)
    {
        GLint programLogLength = 0;
        glGetProgramiv(program, GL_INFO_LOG_LENGTH, &programLogLength);

        std::vector<GLchar> programLog(programLogLength);
        glGetProgramInfoLog(program, programLogLength, nullptr, programLog.data());
        programLog[programLogLength - 1] = '\0';

        spdlog::error("Shader compilation failed: {}", programLog.data());
    }
}
