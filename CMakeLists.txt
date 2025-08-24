cmake_minimum_required(VERSION 3.5.0)
project(tetris VERSION 0.1.0 LANGUAGES C)
include(FetchContent)

FetchContent_Declare(SDL2
    URL https://github.com/libsdl-org/SDL/releases/download/release-2.32.2/SDL2-2.32.2.tar.gz
)
FetchContent_MakeAvailable(SDL2)

FetchContent_Declare(SDL2_image
    URL https://github.com/libsdl-org/SDL_image/releases/download/release-2.8.8/SDL2_image-2.8.8.tar.gz
)
FetchContent_MakeAvailable(SDL2_image)

add_executable(tetris main.c src/window.c src/app.c src/object_pool.c src/texture.c)

target_link_libraries(tetris SDL2::SDL2 SDL2_image::SDL2_image dl m)

target_compile_options(tetris PRIVATE -std=c99 -Wall -Wextra -g)

include(CTest)
enable_testing()