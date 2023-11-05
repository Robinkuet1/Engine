#include "Core/Window.h"

#include <GLFW/glfw3.h>
#include <GL/gl.h>

Window::Window()
{

}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void Window::init() 
{
    //todo add error callback
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(640, 480, "example", NULL, NULL);
    if (!this->window)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(this->window);
}

void Window::update()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

Window& Window::get() 
{
    static Window window;

    return window;
}