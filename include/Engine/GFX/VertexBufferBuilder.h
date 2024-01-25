#pragma once
#include <memory>
#include <vector>

#include "Engine/Core/Defines.h"

#include "VertexBuffer.h"
#include "glad/glad.h"

enum VertexAttributeType {
  FLOAT = GL_FLOAT,
  INT = GL_INT,
  UINT = GL_UNSIGNED_INT,
};

class VertexBufferBuilder {
public:
  explicit VertexBufferBuilder(string name = "");
  ~VertexBufferBuilder();

  VertexBufferBuilder& AddVertexDataDirect(const std::vector<f32>& vertices);
  VertexBufferBuilder& AddIndexDataDirect(const std::vector<u32>& indices);
  VertexBufferBuilder& AddVertexAttribute(i32 size, VertexAttributeType type = FLOAT);

  [[nodiscard]] std::unique_ptr<VertexBuffer> Build() const;

private:
  u32 attribIndex = 0;
  u32 size = 0;
  u32 VBO = 0, VAO = 0, EBO = 0;
};
