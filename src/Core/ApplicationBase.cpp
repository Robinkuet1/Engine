//must be included before glfw
#include <glad/glad.h>

#include "Engine/Core/ApplicationBase.h"
#include "Engine/Core/Window.h"


ApplicationBase::ApplicationBase() {
    //do nothing
}

void ApplicationBase::Run() {
    Window::Get();
    OnInitialize();
    while (!Window::Get().ShouldClose()) {
        Window::Get().BeginFrame();
        Window::Get().Clear();
        OnUpdate(Window::Get().GetDeltaTime());
        OnRender();
        Window::Get().EndFrame();
    }
    OnShutdown();
}
