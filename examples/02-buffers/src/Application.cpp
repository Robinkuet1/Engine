#include "Application.h"
#include "Engine/GFX/VertexBufferBuilder.h"

#include <iostream>

void Application::OnInitialize() {
    std::cout << "Hello World\n";
    VertexBufferBuilder builder{};
    this->buffer = builder
        .AddVertexDataDirect({
          -0.5f, -0.5f, 0.0f,
          0.5f, -0.5f, 0.0f,
          0.0f,  0.5f, 0.0f
        })
        .AddVertexAttribute(3)
        .Build();
}

void Application::OnUpdate(f64 delta) {

}

void Application::OnRender() {
  this->buffer->Draw();
}

void Application::OnShutdown() {

}
