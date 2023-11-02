#include "Core/Application.h"
#include <iostream>

Application::Application() :
    window(new Window())
{
    std::cout << "Hello World\n";

    while (1)
    {
        this->window->update();
    }
}