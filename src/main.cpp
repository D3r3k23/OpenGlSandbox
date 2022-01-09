#include "Application.hpp"

#include <spdlog/spdlog.h>

int main(int argc, char* argv[])
{
    spdlog::info("Initializing OpenGL Sandbox App");
    Application app;

    spdlog::info("Running OpenGL Sandbox App");
    app.run();

    spdlog::info("Exiting");
    return 0;
}
