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
     texture_Init(window.renderer);
    // Initalize the game and piece states
    game_Init();
    game_spawnNewPiece(TETRIS_BAR);
    game_PrintGrid();
   

    while (window.is_open)
    {   
         SDL_RenderClear(window.renderer);
         game_Draw(window.renderer);
       //  SDL_RenderCopy(window.renderer, text, NULL, &texture_rect );
        window_renderWindow(&window);
        
    }       

    window_DestroyWindow(&window);
    object_DestroyPool();


    return 0;
}