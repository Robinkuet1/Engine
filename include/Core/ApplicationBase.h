#include "Core/Window.h"

class ApplicationBase
{
public:
    ApplicationBase() = delete;
    ~ApplicationBase() = delete;

    virtual void OnUpdate();
};