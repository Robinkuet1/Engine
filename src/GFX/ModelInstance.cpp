#include <Engine/GFX/ModelInstance.h>

#include <utility>

ModelInstance::ModelInstance(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader) : model(std::move(model)), shader(std::move(shader)) {}

void ModelInstance::Draw() {
  this->shader->Use();
  this->shader->UniformMatrix("model", this->transform.GetModelMatrix());
  for(auto& buffer : this->model->buffers) {
    buffer->Draw();
  }
}

