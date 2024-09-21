#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "include/sprite.h"
#include "include/game.h"

int main()
{
    
    m_create_window(320, 640);


    m_game_start();
  

    m_render_window();
    m_destroy_window();

    return 0;
}