cmake_minimum_required(VERSION 3.13)
project(models)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_subdirectory(../../ build)

add_executable(models
        #sources
        src/main.cpp
        src/Application.cpp

        #headers
        include/Application.h
)

target_include_directories(models PUBLIC ../../include)
target_include_directories(models PUBLIC include)

target_link_libraries(models engine)