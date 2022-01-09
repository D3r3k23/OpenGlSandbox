#include "Renderer.hpp"

Renderer::Renderer(void)
{

}

Renderer::~Renderer(void)
{

}

void Renderer::init(void)
{
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

void Renderer::begin_frame(void)
{

}

void Renderer::render(void)
{

}

void Renderer::end_frame(void)
{

}

void Renderer::set_viewport(int x,  int y, unsigned width, unsigned height)
{
    glViewport(x, y, width, height);
}
