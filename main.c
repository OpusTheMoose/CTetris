#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "include/sprite.h"

int main()
{
    
    m_create_window(320, 600);

    // m_createSprite(0, 0, 32, 32, "include/tile.png");
    // m_createSprite(0, 32, 32, 32, "include/tile.png");
    m_createTetromino(0, 0, 32, 32, "include/tile.png", 0 );
    m_createTetromino(128, 0, 32, 32, "include/tile.png", 1 );
    m_createTetromino(128, 64, 32, 32, "include/tile.png", 2 );
    m_createTetromino(128, 128, 32, 32, "include/tile.png", 3 );
    m_createTetromino(128, 320, 32, 32, "include/tile.png", 4 );

    m_render_window();
    m_destroy_window();

    return 0;
}