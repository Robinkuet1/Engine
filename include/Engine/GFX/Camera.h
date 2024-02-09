#pragma once

#include <glm/glm.hpp>


class Camera {
public:
  virtual ~Camera() = default;

  virtual void OnUpdate() = 0;
  [[nodiscard]] const glm::mat4& GetProjView() const;

  void Update();
  void SetPosition(glm::vec3 newPos);
private:
  void updateMatrix();
  Camera() = default;

  glm::vec3 position = glm::vec3(0);
  glm::vec3 rotation = glm::vec3(0);

  glm::mat4 projView = glm::mat4(1);
};