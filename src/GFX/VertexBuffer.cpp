#include "Engine/GFX/VertexBuffer.h"

#include "Engine/Core/Log.h"
#include <glad/glad.h>

VertexBuffer::VertexBuffer() {
}

VertexBuffer::~VertexBuffer() {
  glDeleteVertexArrays(1, &this->VAO);
  glDeleteBuffers(1, &this->VBO);
  glDeleteBuffers(1, &this->EBO);
}

void VertexBuffer::Use() {
  LOG_INFO("VBO:", this->VBO, "VAO:", this->VAO, "Size:", this->size);
}

void VertexBuffer::Draw() {
  glBindVertexArray(this->VAO);

  if (this->EBO) {
    glDrawElements(GL_TRIANGLES, this->size, GL_UNSIGNED_INT, nullptr);
  }else {
    glDrawArrays(GL_TRIANGLES, 0, this->size);
  }

  glBindVertexArray(0);
}
