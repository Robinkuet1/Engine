#include "Application.h"
#include "Engine/GFX/VertexBufferBuilder.h"

#include <iostream>

#include "imgui.h"
#include "Engine/GFX/ShaderBuilder.h"
#include "Engine/GFX/ModelLoader.h"

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

  model = ModelLoader::LoadFromZip("/home/kuttelr/work/cpp/model-converter/cmake-build-debug/backpack/backpack.zip");
}

void Application::OnUpdate(f64 delta) {
}

void Application::OnRender() {
}

void Application::OnShutdown() {
}
