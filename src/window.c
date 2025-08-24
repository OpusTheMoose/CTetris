#include <SDL2/SDL.h>
#include "../include/window.h"


Window window_newWindow(unsigned int width, unsigned int height)
{
    Window window;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("ERROR: Failed to initalize SDL2. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }
    window.window = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0 );
    if (!window.window)
    {
        printf("ERROR: Failed to create window. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }
 
    window.is_open = SDL_TRUE;
    window.renderer = SDL_CreateRenderer(window.window, 0, 0);
    if (!window.renderer)
    {
        printf("ERROR: Failed to create renderer. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }
    printf("Window created \n");
    return window;
}
void window_renderWindow(Window* window)
{
 
      // int current_frame = SDL_GetTicks64();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    window->is_open = SDL_FALSE;
                    break;
                // case SDL_KEYDOWN:
                //    // m_handle_input(event.key.keysym.sym);
                //     break;
                    
            }
        }
        SDL_RenderClear(window->renderer);
        
        SDL_RenderPresent(window->renderer);
      //  last_frame = current_frame;
    
}
void window_DestroyWindow(Window *window)
{
    printf("Destroying window... \n");
    SDL_DestroyRenderer(window->renderer);
    SDL_DestroyWindow(window->window);
  
    
}