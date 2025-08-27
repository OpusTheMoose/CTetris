#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "include/window.h"
#include "include/object_pool.h"
#include "include/game.h"

#define MAX_SPRITES 500

typedef struct{
    SDL_Rect rect;
    uint8_t texture;
} Sprite;

int main()
{
    object_ObjectPool(MAX_SPRITES, sizeof(Sprite));
    Window window = window_newWindow(SCREEN_WIDTH, SCREEN_HEIGHT);
    // Initalize the game and piece states
    game_Init();
    game_PrintGrid();

    // Initialize SDL2_image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Failed to initialize SDL2_image: %s\n", IMG_GetError());
        return 1;
    }

    SDL_Texture *text = IMG_LoadTexture(window.renderer, "include/tile.png");
    if (text == NULL)
    {
        printf("Failed to load texture \n");
    }
    SDL_Rect texture_rect = {200, 200, 32, 32};
    while (window.is_open)
    {   
         SDL_RenderClear(window.renderer);
         SDL_RenderCopy(window.renderer, text, NULL, &texture_rect );
        window_renderWindow(&window);
        
    }       

    window_DestroyWindow(&window);
    object_DestroyPool();

    return 0;
}