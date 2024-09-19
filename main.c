#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"

int main()
{
    m_create_window(200, 600);
    m_render_window();
    m_destroy_window();

    return 0;
}