#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "include/sprite.h"

int main()
{
    
    m_create_window(200, 600);

    m_createSprite(80, 80, "../../../include/TEST_TEXTURE.png");

    m_render_window();
    m_destroy_window();

    return 0;
}