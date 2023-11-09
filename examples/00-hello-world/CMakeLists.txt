cmake_minimum_required(VERSION 3.13)
project(hello-world)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(../../ build)

add_executable(hello-world
        #sources
        src/main.cpp
        src/Application.cpp

        #headers
        include/Application.h
)

target_include_directories(hello-world PUBLIC ../../include)
target_include_directories(hello-world PUBLIC include)

target_link_libraries(hello-world engine)