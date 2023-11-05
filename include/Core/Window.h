#pragma once

#include "Core/defines.h"

//forward declarations
class GLFWwindow;

class Window
{
public:
    Window(Window const&) = delete;
    void operator=(Window const&) = delete;
    
    void init();
    void update();
    static Window& get();

private:
    Window(); //private constructor to not allow instantiations outside of this singleton
    ~Window();

    GLFWwindow* window;
};