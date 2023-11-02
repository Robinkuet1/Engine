#include "Core/defines.h"
#include <GLFW/glfw3.h>

#include <GL/gl.h>

class Window
{
public:
    Window();
    ~Window();
    
    void update();

private:
    GLFWwindow* window;
};