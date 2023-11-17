#include "Engine/Core/ApplicationBase.h"
#include "Engine/Core/Window.h"


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
