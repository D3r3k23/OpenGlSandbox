#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Renderer.hpp"

#include <GLFW/glfw3.h>

class Application
{
public:
    Application(void);
    ~Application(void);

    void run(void);

private:
    void begin_frame(void);
    void end_frame(void);

private:
    GLFWwindow* m_window;
    bool m_showDemoWindow;

    Renderer m_renderer;
};

#endif // APPLICATION_HPP
