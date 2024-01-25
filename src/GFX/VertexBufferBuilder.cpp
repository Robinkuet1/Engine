#include "Engine/GFX/VertexBufferBuilder.h"

#include "Engine/Core/Log.h"
#include "glad/glad.h"

VertexBufferBuilder::VertexBufferBuilder(string name) {
}

VertexBufferBuilder::~VertexBufferBuilder() = default;

VertexBufferBuilder& VertexBufferBuilder::AddVertexDataDirect(const std::vector<f32>& vertices) {
  //bind and create vao
  glGenVertexArrays(1, &this->VAO);
  ASSERT(this->VAO != 0 && "VAO generation failed")

  glGenBuffers(1, &this->VBO);
  ASSERT(this->VBO != 0 && "Vertex Buffer generation failed")

  glBindVertexArray(this->VAO);

  glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
  glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(f32), vertices.data(), GL_STATIC_DRAW);

  return *this;
}

VertexBufferBuilder& VertexBufferBuilder::AddIndexDataDirect(const std::vector<u32>& indices) {
  glBindVertexArray(this->VAO);
  ASSERT(this->VAO != 0 && "Index Buffer generation failed")

  glGenBuffers(1, &this->EBO);
  ASSERT(this->EBO != 0 && "Index Buffer generation failed")

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(u32), indices.data(), GL_STATIC_DRAW);
  this->size = indices.size();

  return *this;
}

long getSizeOfVertexAttributeType(VertexAttributeType type) {
  switch (type) {
    case INT:
      return 4;
    case UINT:
      return 4;
    case FLOAT:
      return 4;
    default:
      LOG_ERROR("Vertex Attrib Type defined incorrectly")
      return -1;
  }
}

VertexBufferBuilder& VertexBufferBuilder::AddVertexAttribute(i32 size, VertexAttributeType type) {
  ASSERT(this->VAO != 0 && "VAO Object not created. You have to add the vertex data before you can set the attributes.");
  ASSERT(this->VBO != 0 && "VBO Object not created. You have to add the vertex data before you can set the attributes.");
  ASSERT(this->EBO != 0 && "EBO Object not created. You have to add the index data before you can set the attributes.");

  //bind
  glBindVertexArray(this->VAO);

  glVertexAttribPointer(attribIndex, size, GL_FLOAT, GL_FALSE, 3 * 4, (void*)0);
  glEnableVertexAttribArray(attribIndex++);

  //unbind vao
  glBindVertexArray(0);

  return *this;
}

std::unique_ptr<VertexBuffer> VertexBufferBuilder::Build() const {
  LOG_ERROR_COND(!this->VAO, "Error VAO was not Generated")
  LOG_ERROR_COND(!this->VBO, "Error VBO was not Generated")
  LOG_ERROR_COND(!this->EBO, "Error EBO was not Generated")
  auto x = std::make_unique<VertexBuffer>();
  x->VBO = this->VBO;
  x->VAO = this->VAO;
  x->EBO = this->EBO;
  x->size = this->size;
  return x;
}