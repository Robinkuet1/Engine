#pragma once

#include <memory>
#include <vector>
#include <utility>

#include "Shader.h"

class ShaderBuilder {
public:
  explicit ShaderBuilder(string name = "");

  ~ShaderBuilder();

  ShaderBuilder(const ShaderBuilder&) = delete;

  ShaderBuilder& operator=(const ShaderBuilder&) = delete;

  ShaderBuilder& addShader(GLenum shaderType, const string& shaderSource);

  ShaderBuilder& addShaderFromFile(GLenum shaderType, const string& filePath);

  ShaderBuilder& setShaderDefine(const string& defines);

  ShaderBuilder& setShaderIncludePath(GLenum shaderType, const string& includePath);

  ShaderBuilder& setShaderAttributeLocation(const string& attributeName, GLuint location);

  ShaderBuilder& setShaderUniformBlockBinding(const string& blockName, GLuint bindingPoint);

  /**
   * @brief With this the shader source is included in the shader object to allow use of the recompile method
   * */
  ShaderBuilder& enableRecompile();

  [[nodiscard]] std::unique_ptr<Shader> Build();

private:
  bool recompile = false;
  string name;
  std::unique_ptr<Shader> shader;
  std::vector<GLint> shaders;
};
