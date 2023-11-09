#include "Engine/Core/ApplicationBase.h"
#include "Engine/Core/Window.h"


void ApplicationBase::Run() {
    Window::Get();
    OnInitialize();
    while (!Window::Get().ShouldClose()) {
        Window::Get().Update();
        OnUpdate(Window::Get().GetDeltaTime());
        OnRender();
    }
    OnShutdown();
}
