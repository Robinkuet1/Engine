#include "Core/Window.h"
#include "GLFW/glfw3.h"
#include <iostream>

#include <GL/gl.h>
#include <zstr.hpp>

Window::Window()
{
    //todo add error callback
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->window = glfwCreateWindow(640, 480, "example", NULL, NULL);
    if (!this->window)
    {
    glfwTerminate();
    exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(this->window);
}

Window::~Window()
{
    glfwDestroyWindow(this->window);
    glfwTerminate();
}

void Window::update()
{
    glfwSwapBuffers(this->window);
    glfwPollEvents();
    glClearColor(1,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}