#ifndef SANDBOX_HPP
#define SANDBOX_HPP

#include <glad/glad.h>

#include <string_view>
#include <initializer_list>

class Sandbox
{
public:
    Sandbox(void);
    ~Sandbox(void);

    void render(void);

private:
    void compile_shader(GLuint shader, std::string_view src);
    void link_shader_program(GLuint program, std::initializer_list<GLuint> shaders);

private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint shaderProgram;

    GLuint cubeVertexBuffer;
    GLuint cubeIndexBuffer;
    GLuint cubeVertexArray;
};

#endif // SANDBOX_HPP
