cmake_minimum_required(VERSION 3.13)
project(engine)

if (${CMAKE_SYSTEM_NAME} STREQUAL "Emscripten")
  option(BUILD_HTML "Build html also!" ON)

  set(EMSCRIPTEN TURE)
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

add_library(engine
        #sources
        src/Core/Application.cpp
        src/Core/Window.cpp

        #headers
        include/Core/defines.h
        include/Core/Application.h
        include/Core/Window.h
)

if (NOT EMSCRIPTEN)
  add_subdirectory(external/glfw)
  target_include_directories(engine PUBLIC external/glfw/include)
  target_link_libraries(engine glfw)
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
target_include_directories(engine PUBLIC include)

target_link_libraries(engine glm)
target_link_libraries(engine zstr::zstr)