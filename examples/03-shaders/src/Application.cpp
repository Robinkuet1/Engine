#include "Application.h"
#include "Engine/GFX/VertexBufferBuilder.h"

#include <iostream>

#include "imgui.h"
#include "Engine/GFX/ShaderBuilder.h"

void Application::OnInitialize() {
  std::cout << "Hello World\n";

  ShaderBuilder shaderBuilder{};
  this->shader = shaderBuilder
      .addShader(
        GL_VERTEX_SHADER,
        "#version 460 core\nlayout (location = 0) in vec3 aPos;\nvoid main(){ gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0); }")
      .addShader(
        GL_FRAGMENT_SHADER,
        "#version 460 core\nout vec4 FragColor;\nvoid main(){ FragColor = vec4(1.0f, 0.0f, 0.0f, 1.0f); }")
      .Build();
}

void Application::OnUpdate(f64 delta) {
}

void Application::OnRender() {
  std::vector<f32> vertices = {
    0.5f, 0.5f, 0.0f, // top right
    0.5f, -0.5f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, // bottom left
    -0.5f, 0.5f, 0.0f // top left
  };

  std::vector<u32> indices = {
    0, 1, 3, // first Triangle
    1, 2, 3 // second Triangle
  };

  VertexBufferBuilder builder{};
  this->buffer = builder
      .AddVertexDataDirect(vertices)
      .AddIndexDataDirect(indices)
      .AddVertexAttribute(3)
      .Build();

  this->shader->Use();
  this->buffer->Draw();
}

void Application::OnShutdown() {
}
