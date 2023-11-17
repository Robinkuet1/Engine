#include "Engine/Core/Input.h"
#include "Engine/Core/Log.h"

#include <GLFW/glfw3.h>

void Input::Initialize() {
    Input::window = Window::Get().m_pWindow;
    if(!Input::window) {
        LOG_ERROR("Window Singleton has to be constructed before Input can be initialized")
    }

    glfwSetKeyCallback(Input::window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
        if(action == GLFW_PRESS){
            for (auto& c : Input::OnKeyDownCallback) {
                c((Key)key);
            }
            for (auto& c : Input::OnSpecificKeyDownCallback[(Key)key]){
                c();
            }
        }
    });
}

bool Input::IsKeyDown(Key k) {
    return glfwGetKey(Input::window, k) == GLFW_PRESS;
}

void Input::OnKeyDown(std::function<void(Key)> f) {
    Input::OnKeyDownCallback.push_back(f);
}

void Input::OnKeyDown(Key k, std::function<void()> f) {
    Input::OnSpecificKeyDownCallback[k].push_back(f);
}

