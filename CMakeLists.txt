cmake_minimum_required(VERSION 3.22)
project(escape)

set(CMAKE_CXX_STANDARD 14)

add_executable(escape main.cpp Game.cpp Game.h Draw.cpp Draw.h Vec2.cpp Vec2.h)
target_link_libraries(escape SDL2)