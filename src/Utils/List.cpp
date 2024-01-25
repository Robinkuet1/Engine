#include "Engine/Utils/List.h"

#include "Engine/Core/Log.h"

template<typename T>
List<T>::List(const u64 capacity): capacity(capacity), length(0), data(nullptr) {
  if(capacity) {
    data = new T[capacity];
  }
}

template<typename T>
List<T>::~List() {
  delete data;
}

template<typename T>
void List<T>::Add(const T& newItem) {
  if(capacity > length) {

  }
}

template<typename T>
int List<T>::GetNewSize() {
  switch (this->size) {
    case SMALL:
      return this->size + 8;
    case MEDIUM:
      return this->size * 2;
    case LARGE:
      return this->size * this->size;
  }

  LOG_ERROR("Size of List not declared")
  return -1;
}
