#include "Engine/GFX/Camera.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const glm::mat4& Camera::GetProjView() const {
  return this->projView;
}

void Camera::Update() {
  this->OnUpdate();
}

void Camera::updateMatrix() {
  const glm::mat4 proj = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 1.0f, 10.0f);
  const glm::mat4 view = glm::lookAt(
    this->position,
    glm::vec3(0.0f, 0.0f, 0.0f),
    glm::vec3(0.0f, 0.0f, 1.0f)
  );

  this->projView = proj * view;
}
