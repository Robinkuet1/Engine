#include "Engine/Core/Window.h"

#include <GLFW/glfw3.h>
#include <GL/gl.h>

Window::Window()
{
    //todo add error callback
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    this->m_pWindow = glfwCreateWindow(640, 480, "example", NULL, NULL);
    if (!this->m_pWindow)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(this->m_pWindow);
}

Window::~Window()
{
    glfwDestroyWindow(this->m_pWindow);
    glfwTerminate();
}

void Window::Update()
{
    glfwSwapBuffers(this->m_pWindow);
    glfwPollEvents();
    m_deltaTime = glfwGetTime() - m_lastTime;
    m_lastTime = glfwGetTime();
}

Window& Window::Get()
{
    static Window window;
    return window;
}

bool Window::ShouldClose() {
#ifdef DEBUG
    return glfwWindowShouldClose(this->m_pWindow) || glfwGetKey(this->m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS;
#else
    return glfwWindowShouldClose(this->window);
#endif
}

void Window::Close() {
    glfwSetWindowShouldClose(this->m_pWindow, true);
}

void Window::Clear() {
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
}

f64 Window::GetDeltaTime() {
    return m_deltaTime;
}
