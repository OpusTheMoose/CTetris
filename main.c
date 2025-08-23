#include <SDL2/SDL.h>
#include <stdio.h>
#include "include/window.h"
#include "include/object_pool.h"

int main()
{
    object_ObjectPool(10, sizeof(int));
    window_newWindow(SCREEN_WIDTH, SCREEN_HEIGHT);

    window_renderWindow();
    object_DestroyPool();

    return 0;
}