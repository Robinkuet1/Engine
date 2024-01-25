#include "Engine/GFX/Shader.h"

Shader::Shader() {
}

Shader::~Shader() {
}

void Shader::Use() {
  glUseProgram(this->programId);
}
