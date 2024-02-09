#include "Engine/Math/Transform.h"

#include <glm/vec3.hpp>
#include <glm/fwd.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 Transform::GetModelMatrix() {
  auto model = glm::mat4(1.0f);

  model = glm::rotate(model, glm::radians(0.f), rotation);
  model = glm::scale(model, scale);

  return model;
}

