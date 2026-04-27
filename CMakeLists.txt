cmake_minimum_required(VERSION 3.10)

project(ConsolePaint)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(target_exec
    src/main.cpp
    src/Canvas.cpp
    src/PaintApp.cpp
)

target_include_directories(target_exec PRIVATE include)
