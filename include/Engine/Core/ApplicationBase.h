#include "Window.h"

class ApplicationBase
{
public:
    ApplicationBase() = default;
    ~ApplicationBase() = default;

    void Run();

protected:
    virtual void OnInitialize() = 0;
    virtual void OnUpdate(f64 delta) = 0;
    virtual void OnRender() = 0;
    virtual void OnShutdown() = 0;
};