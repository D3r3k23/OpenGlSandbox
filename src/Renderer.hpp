#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <glad/glad.h>

class Renderer
{
public:
    Renderer(void);
    ~Renderer(void);

    void init(void);

    void begin_frame(void);
    void render(void);
    void end_frame(void);

    void set_viewport(int x,  int y, unsigned width, unsigned height);

private:
};

#endif // RENDERER_HPP
