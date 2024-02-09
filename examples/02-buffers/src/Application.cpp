#include "Application.h"
#include "Engine/GFX/VertexBufferBuilder.h"

#include <iostream>

#include "Engine/Core/Log.h"

void Application::OnInitialize() {
  LOG_INFO("On some systems, buffers need to have a shader before they are displayed")

  VertexBufferBuilder builder{};
  const std::vector<f32> vertices = {
    0.5f, 0.5f, 0.0f, // top right
    0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f // top left
  };

  const std::vector<u32> indices = {
    0, 1, 3, // first Triangle
    1, 2, 3 // second Triangle
  };

  VertexBufferBuilder bufferBuilder{};
  this->buffer = bufferBuilder
      .AddVertexDataDirect(vertices)
      .AddIndexDataDirect(indices)
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
