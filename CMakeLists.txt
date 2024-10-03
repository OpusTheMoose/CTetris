cmake_minimum_required(VERSION 3.5.0)
project(tetris VERSION 0.1.0 LANGUAGES C)

find_package(SDL2 REQUIRED)
include_directories(tetris ${SDL2_INCLUDE_DIRS})

add_executable(tetris main.c src/window.c src/sprite.c src/app.c src/game.c src/piece_info.c)
target_link_libraries(tetris ${SDL2_LIBRARIES} dl m SDL2_image)

include(CTest)
enable_testing()

