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
    game_spawnNewPiece(TETRIS_T);
    game_PrintGrid();

   uint64_t last_tick = SDL_GetTicks64();
    float dt = 0.0f;

    while (window.is_open)
    {   
        uint64_t current_tick = SDL_GetTicks64();
        dt = (current_tick - last_tick) / 1000.0f;

        game_Update(dt);

        SDL_RenderClear(window.renderer);
        game_Draw(window.renderer);
       //  SDL_RenderCopy(window.renderer, text, NULL, &texture_rect );
        window_renderWindow(&window);

        SDL_Delay(16); // Stops for 16 ms, or 60 FPS
        
        last_tick = current_tick;

    }       

    window_DestroyWindow(&window);
    object_DestroyPool();


    return 0;
}