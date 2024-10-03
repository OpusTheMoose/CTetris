#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "include/sprite.h"
#include "include/game.h"

int main()
{
    
    m_create_window(SCREEN_WIDTH, SCREEN_HEIGHT);


    m_game_start();
  
    //Update loop. Updates game events as well
    m_render_window();

    m_destroy_window();

    return 0;
}