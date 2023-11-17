#include "Engine/Core/Window.h"

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

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

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsLight();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(m_pWindow, true);
    ImGui_ImplOpenGL3_Init("#version 460");
}

Window::~Window()
{
    glfwDestroyWindow(this->m_pWindow);
    glfwTerminate();
}

void Window::BeginFrame()
{
    glfwSwapBuffers(this->m_pWindow);
    glfwPollEvents();
    // Start the Dear ImGui frame
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    m_deltaTime = glfwGetTime() - m_lastTime;
    m_lastTime = glfwGetTime();
}

void Window::EndFrame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
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
