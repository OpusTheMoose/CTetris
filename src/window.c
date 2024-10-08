#include "../include/window.h"
#include "../include/app.h"
#include "../include/sprite.h"
#include "../include/game.h"


/*
0 = MOVE_LEFT
1 = MOVE_RIGHT
2 = DROP
3 = ROTATE_RIGHT
4 = ROTATE_LEFT
*/


void m_create_window(unsigned int width, unsigned int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("ERROR: Failed to initalize SDL2. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }
    app.window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0 );
    if (!app.window)
    {
        printf("ERROR: Failed to create window. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }
 
    app.window_open = true;
    app.renderer = SDL_CreateRenderer(app.window, 0, 0);
    if (!app.renderer)
    {
        printf("ERROR: Failed to create renderer. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }


}
void m_render_window()
{
    int last_frame = 0;
    while (app.window_open)
    {
       int current_frame = SDL_GetTicks64();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    app.window_open = false;
                    break;
                case SDL_KEYDOWN:
                    m_handle_input(event.key.keysym.sym);
                    break;
                    
            }
        }
        SDL_RenderClear(app.renderer);
        
        m_game_update(current_frame - last_frame);

       // m_update_sprites();
        
        for (int i = 0; i < num_of_sprites; i++)
        {
            
            SDL_RenderCopy(app.renderer, sprite_list[i].texture, NULL, &sprite_list[i].texture_rect);
        }
        SDL_Rect rect;
        rect.h = SCREEN_HEIGHT;
        rect.w = 10;
        rect.x = 320;
        rect.y = 0;
        SDL_SetRenderDrawColor(app.renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(app.renderer, &rect);
         SDL_SetRenderDrawColor(app.renderer, 0,0, 0, SDL_ALPHA_OPAQUE);

         
       
      
        SDL_RenderPresent(app.renderer);
         last_frame = current_frame;
    }
}
void m_destroy_window()
{
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    for (int i = 0; i < num_of_sprites; i++)
    {
        SDL_DestroyTexture(sprite_list[i].texture);
    }
    free(sprite_list);
    
}