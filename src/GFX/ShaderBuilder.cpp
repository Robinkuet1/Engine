#include <utility>

#include "Engine/GFX/ShaderBuilder.h"

#include "Engine/Core/Log.h"
#include "Engine/Core/Window.h"

ShaderBuilder::ShaderBuilder(string name) : name(std::move(name)){
  shader = std::make_unique<Shader>();
  shader->programId = glCreateProgram();
}

ShaderBuilder::~ShaderBuilder() {

}

ShaderBuilder& ShaderBuilder::enableRecompile() {
  this->recompile = true;

  return *this;
}

std::unique_ptr<Shader> ShaderBuilder::Build() {
  glLinkProgram(shader->programId);

  int success = 0;
  glGetProgramiv(shader->programId, GL_LINK_STATUS, &success);
  if(!success) {
    char infoLog[1024];
    glGetProgramInfoLog(shader->programId, 1024, nullptr, infoLog);
    LOG_ERROR("Failed to link program in shader", name, "with error:", infoLog)
  }

  for(const auto s : shaders) {
    glDeleteShader(s);
  }

  return std::move(shader);
}

static string shaderTypeToString(const GLenum type) {
  switch (type) {
    case GL_VERTEX_SHADER: return "VERTEX";
    case GL_FRAGMENT_SHADER: return "FRAGMENT";
    default: return "UNKNOWN";
  }
}

ShaderBuilder &ShaderBuilder::addShader(GLenum shaderType, const string &shaderSource) {
  const char* source = shaderSource.c_str();
  int success{0};

  GLint s = glCreateShader(shaderType);
  glShaderSource(s, 1, &source, nullptr);
  glCompileShader(s);

  glGetShaderiv(s, GL_COMPILE_STATUS, &success);
  if (!success)
  {
    char infoLog[1024];
    glGetShaderInfoLog(s, 1024, NULL, infoLog);
    LOG_ERROR("Failed to compile", shaderTypeToString(shaderType), "shader in", name, "program", "with error:", infoLog)
  }

  glAttachShader(shader->programId, s);

  return *this;
}

