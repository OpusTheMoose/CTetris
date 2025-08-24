#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "include/object_pool.h"

typedef struct{
    SDL_Rect rect;
} Sprite;

int main()
{
    object_ObjectPool(10, sizeof(Sprite));
    Window window = window_newWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    while (window.is_open)
    {   
        window_renderWindow(&window);
    }       

    window_DestroyWindow(&window);
    object_DestroyPool();

    return 0;
}