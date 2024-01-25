#pragma once
#include "Engine/Core/Defines.h"

enum ListSize : u8{
  SMALL = 0, //
  MEDIUM = 1,
  LARGE = 2,
};

template <typename T>
class List {
public:
  explicit List(u64 capacity = 0);
  ~List();

  void Add(const T& newItem);

  void SetSize(const ListSize& newSize);

private:
  ListSize size = MEDIUM;
  u64 capacity, length;
  T* data;

  int GetNewSize();
  void Resize();
};

