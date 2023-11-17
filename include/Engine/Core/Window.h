#pragma once

#include "Engine/Core/Defines.h"

//forward declarations
class GLFWwindow;

class Window
{
public:
    friend class Input;

    Window(Window const&) = delete;
    void operator=(Window const&) = delete;
    
    void BeginFrame();
    void EndFrame();

    static Window& Get();

    bool ShouldClose();

    void Clear();
    void Close();

    f64 GetDeltaTime();

private:
    Window(); //private constructor to not allow instantiations outside of this singleton
    ~Window();

    f64 m_lastTime = 0;
    f64 m_deltaTime = 0;

    GLFWwindow* m_pWindow = nullptr;
};