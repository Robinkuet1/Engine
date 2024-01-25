#pragma once
#include <map>
#include <memory>

#include <glad/glad.h>

#include "Engine/Core/Defines.h"

class Shader {
  friend class ShaderBuilder;
  friend std::unique_ptr<Shader> std::make_unique<Shader>();

public:
  ~Shader();

  /**
   * \brief Set this shader as Active
   */
  void Use();
  void UniformF64(string location, f64 data);

private:
  Shader();

  GLuint programId;
  GLuint vertexId, fragmentId;
  std::map<string, GLuint> uniformLocations;
};
