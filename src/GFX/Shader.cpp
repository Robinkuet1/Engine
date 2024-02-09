#include "Engine/GFX/Shader.h"

Shader::Shader() {
}

Shader::~Shader() {
}

void Shader::Use() {
  glUseProgram(this->programId);
}

void Shader::UniformF64(string location, f64 data) {

}

void Shader::UniformMatrix(string location, glm::mat4 matrix) {

}

