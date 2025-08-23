#include "../include/window.h"
#include "../include/app.h"



/*
0 = MOVE_LEFT
1 = MOVE_RIGHT
2 = DROP
3 = ROTATE_RIGHT
4 = ROTATE_LEFT
*/


void window_newWindow(unsigned int width, unsigned int height)
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
 
    app.window_open = SDL_TRUE;
    app.renderer = SDL_CreateRenderer(app.window, 0, 0);
    if (!app.renderer)
    {
        printf("ERROR: Failed to create renderer. \n");
        printf("%s", SDL_GetError());
        exit(0);
    }


}
void window_renderWindow()
{
  //  int last_frame = 0;
    while (app.window_open)
    {
      // int current_frame = SDL_GetTicks64();
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    app.window_open = SDL_FALSE;
                    break;
                // case SDL_KEYDOWN:
                //    // m_handle_input(event.key.keysym.sym);
                //     break;
                    
            }
        }
        SDL_RenderClear(app.renderer);
        
        SDL_RenderPresent(app.renderer);
      //   last_frame = current_frame;
    }
}
void window_DestroyWindow()
{
    SDL_DestroyRenderer(app.renderer);
    SDL_DestroyWindow(app.window);
  
    
}