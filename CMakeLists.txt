cmake_minimum_required(VERSION 3.24)
project(snakeGame)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-lncurses")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(snakeGame main.cpp game/eatable/Eatable.h game/eatable/Eatable.cpp game/eatable/Fruit.cpp game/eatable/Fruit.h game/eatable/Poison.h game/eatable/Poison.cpp game/Object.cpp game/Object.h game/map/Wall.cpp game/map/Wall.h game/snake/SnakeHead.cpp game/snake/SnakeHead.h game/snake/SnakeTail.cpp game/snake/SnakeTail.h game/snake/SnakeTail.cpp game/snake/SnakeHead.cpp game/Direction.h game/Type.h game/map/ImmuneWall.cpp game/map/ImmuneWall.h game/map/Gate.cpp game/map/Gate.h)

target_link_libraries(snakeGame ncurses)
