cmake_minimum_required(VERSION 3.14)
project(BlockJumpAI)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(BlockJumpAI
    src/main.cpp
    src/player.cpp
    src/wall.cpp
)

