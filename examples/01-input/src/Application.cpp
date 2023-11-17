#include "Application.h"
#include "Engine/Core/Input.h"
#include "Engine/Core/Log.h"

#include <iostream>

void Application::OnInitialize() {
    std::cout << "Hello World\n";
    Input::Initialize();
    Input::OnKeyDown(KEY_W,[](){
        LOG_INFO("Key W pressed")
    });
    Input::OnKeyDown([](Key k){
        LOG_DEBUG("Key with code", k, "Pressed")
    });
}

void Application::OnUpdate(f64 delta) {

}

void Application::OnRender() {

}

void Application::OnShutdown() {

}
