cmake_minimum_required(VERSION 3.13)
project(imgui)

add_library(imgui
        imgui.cpp
        imgui_demo.cpp
        imgui_draw.cpp
        imgui_tables.cpp
        imgui_widgets.cpp

        backends/imgui_impl_glfw.cpp
        backends/imgui_impl_opengl3.cpp

        #headers
        imconfig.h
        imgui.h
        imgui_internal.h
        imstb_rectpack.h
        imstb_textedit.h
        imstb_truetype.h

        backends/imgui_impl_glfw.h
        backends/imgui_impl_opengl3.h
        backends/imgui_impl_opengl3_loader.h
)

target_include_directories(imgui PUBLIC .)
target_include_directories(imgui PUBLIC ../glfw/include)

add_subdirectory(../glfw build)

target_link_libraries(imgui glfw)