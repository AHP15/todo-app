cmake_minimum_required(VERSION 3.27.7)

project(Todo VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED true)

configure_file(TodoConfig.h.in TodoConfig.h)

link_libraries(SDL2)
add_executable(Todo src/main.cpp src/Window.cpp)

include_directories(src/includes)

target_include_directories(Todo PUBLIC "${PROJECT_BINARY_DIR}")
