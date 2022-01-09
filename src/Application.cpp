#include "Application.hpp"

#include "Util.hpp"

#include <glad/glad.h>
#include <spdlog/spdlog.h>

#include <imgui_impl/imgui_impl_glfw.h>
#include <imgui_impl/imgui_impl_opengl3.h>

Application::Application(void)
  : m_showDemoWindow(false)
{
    // GLFW Window
    {
        auto status = glfwInit();
        if (!status)
            spdlog::critical("Failed to initialize GLFW");

        glfwSetErrorCallback([](int error, const char* description)
        {
            spdlog::error("GLFW Error [{}]: {}", error, description);
        });

        m_window = glfwCreateWindow(1280, 710, "OpenGL Sandbox", nullptr, nullptr);
        if (!m_window)
            spdlog::critical("Failed to create GLFW window");

        glfwMakeContextCurrent(m_window);

        glfwSwapInterval(1);
    }

    // OpenGL
    {
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if (!status)
            spdlog::critical("Glad failed to initialize OpenGL context");

        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(gl_message_handler, nullptr);

        int width, height;
        glfwGetFramebufferSize(m_window, &width, &height);
        m_renderer.set_viewport(0, 0, width, height);
    }

    // Events
    {
        glfwSetWindowUserPointer(m_window, static_cast<void*>(this));

        glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
        {
            Application& app = *static_cast<Application*>(glfwGetWindowUserPointer(window));
            app.m_renderer.set_viewport(0, 0, width, height);
        });

        glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scanCode, int action, int mods)
        {
            Application& app = *static_cast<Application*>(glfwGetWindowUserPointer(window));
            switch (key)
            {
                case GLFW_KEY_F12 : app.m_showDemoWindow = !app.m_showDemoWindow;
            }
        });
    }

    // ImGui
    {
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO();

        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        ImGui::StyleColorsDark();

        ImGui_ImplGlfw_InitForOpenGL(m_window, true);
        ImGui_ImplOpenGL3_Init("#version 400");
    }

    m_renderer.init();
}

Application::~Application(void)
{
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext(nullptr);

    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Application::run(void)
{
    while (!glfwWindowShouldClose(m_window))
    {
        begin_frame();
        m_renderer.render();
        end_frame();
    }
}

void Application::begin_frame(void)
{
    glfwPollEvents();

    m_renderer.begin_frame();

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Application::end_frame(void)
{
    if (m_showDemoWindow)
        ImGui::ShowDemoWindow(&m_showDemoWindow);

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    m_renderer.end_frame();

    glfwSwapBuffers(m_window);
}
