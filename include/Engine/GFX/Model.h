#pragma once

#include <vector>
#include "Engine/Math/Transform.h"
#include "VertexBuffer.h"
#include "Shader.h"

/**
 * Model is the collection of a Vertex/Index buffer and some Shaders
 * A model can not be drawn directly but has to be attached to an ModelInstance.
 */
class Model {
  friend class ModelLoader;
  friend class ModelInstance;

private:
  std::vector<VertexBuffer*> buffers;
  Shader* shader;
};