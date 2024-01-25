#pragma once
#include <memory>

#include "Engine/Core/Defines.h"

class VertexBuffer {
  friend class VertexBufferBuilder;
  friend class std::unique_ptr<VertexBuffer>;

public:
  VertexBuffer();
  ~VertexBuffer();

  void Use();
  void Draw();

private:
  u32 VBO, VAO, EBO = 0;
  u32 size;
};
