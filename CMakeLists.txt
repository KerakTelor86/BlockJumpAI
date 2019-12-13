cmake_minimum_required(VERSION 3.14)
project(BlockJumpAI)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
include_directories(include ${SDL2_INCLUDE_DIRS})

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

add_executable(BlockJumpAI
    src/main.cpp
    src/game.cpp
    src/player.cpp
    src/wall.cpp
    src/ai.cpp
)

target_link_libraries(BlockJumpAI
    ${SDL2_LIBRARIES}
    -lSDL2
    -lSDL2_image
    -lSDL2_mixer
    -lSDL2_ttf
    -L/usr/lib
    -lsimple2d
    -lGL
    -lm
    Threads::Threads
)
