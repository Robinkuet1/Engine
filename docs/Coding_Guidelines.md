# C++ Coding Guidelines

## Naming
- Classes in PascalCase
- Private Member variables with m_ prefix (m_p for Pointers) and camelCase
- Public Member variables camelCase without prefix
- Preprocessor Constants in Caps Lock eg. SOME_CONSTANT
- Local variables in camelCase

## Custom types
Use our custom types when ever possible eg. i32 instead of int

## Namespaces
As the scope of this project isn't very big, we don't use Namespaces.

## Header Guards
All header files must protect against multiple includes with the #pragma once flag.
```c++
#pragma once
```

## Includes and forward definitions
- Only include what you need.

- use "" for local files and <> for library files
```c++
#include <glm/vec2.hpp> //libraries
#include "Core/Application.h" //local project files
```

- Prefer forward definitions in Header files
a.h
```c++
#pragma once
class SomeOtherClass;

class SomeClass {
  SomeOtherClass* m_pSomeMember;
};
```
a.cpp
```c++
#include "a.h"

#include "SomeOtherClass.h"
```