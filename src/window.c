#include "../include/window.h"
#include "../include/app.h"
#include "../include/sprite.h"

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
    while (app.window_open)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    app.window_open = false;
                    break;
            }
        }
        SDL_RenderClear(app.renderer);
        SDL_RenderCopy(app.renderer, list_of_sprites[0].texture, NULL, &list_of_sprites[0].texture_rect);
        SDL_RenderPresent(app.renderer);
    }
}
void m_destroy_window()
{
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
    
}