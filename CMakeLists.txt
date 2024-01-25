cmake_minimum_required(VERSION 3.13)
project(engine)

#remove for prod
add_compile_definitions(DEBUG)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  option(BUILD_HTML "Build html also!" ON)

  set(EMSCRIPTEN TRUE)
  set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE BOTH)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

#glfw
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glm)
add_subdirectory(external/zstr)
add_subdirectory(external/imgui)
add_subdirectory(external/glad)

add_library(engine
        #sources
        src/Core/ApplicationBase.cpp
        src/Core/Window.cpp
        src/Core/Input.cpp
        src/GFX/Shader.cpp

        #headers
        include/Engine/Core/Defines.h
        include/Engine/Core/ApplicationBase.h
        include/Engine/Core/Window.h
        include/Engine/Core/Log.h
        include/Engine/GFX/Shader.h
        include/Engine/GFX/ShaderBuilder.h
        src/GFX/ShaderBuilder.cpp
        include/Engine/GFX/VertexBufferBuilder.h
        include/Engine/GFX/VertexBuffer.h
        src/GFX/VertexBufferBuilder.cpp
        src/GFX/VertexBuffer.cpp
        src/GFX/VertexBufferBuilder.cpp
        include/Engine/Utils/List.h
        src/Utils/List.cpp
)

if (NOT EMSCRIPTEN)
  target_include_directories(engine PUBLIC external/glfw/include)
  if (WIN32)
    target_link_libraries(engine opengl32)
  else()
    find_package(OpenGL REQUIRED)
    target_link_libraries(engine ${OPENGL_LIBRARIES})
  endif()
endif()

if (EMSCRIPTEN)
  if (BUILD_HTML)
    set_target_properties(engine PROPERTIES SUFFIX ".html")
  endif()
  target_compile_definitions(engine PUBLIC -DEMSCRIPTEN=1)
  set_target_properties(engine PROPERTIES COMPILE_FLAGS "-Os -s SIDE_MODULE=1 ")
  set_target_properties(engine PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s USE_WEBGL2=1 -s FULL_ES3=1")
endif()

target_include_directories(engine PUBLIC external/glm)
target_include_directories(engine PUBLIC external/imgui)
target_include_directories(engine PUBLIC external/glad)
target_include_directories(engine PUBLIC include)

target_link_libraries(engine glm)
target_link_libraries(engine glad)
target_link_libraries(engine zstr::zstr)
target_link_libraries(engine imgui)