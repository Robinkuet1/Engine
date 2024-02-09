#pragma once

#include <memory>
#include "Model.h"

class ModelInstance {
  ModelInstance(std::shared_ptr<Model> model, std::shared_ptr<Shader> shader);

  void Draw();
public:
  Transform transform;
  std::shared_ptr<Model> model;
  std::shared_ptr<Shader> shader;
};