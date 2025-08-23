#pragma once
#include <SDL2/SDL.h>
#define FALSE 0
#define TRUE 1

struct m_app
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_bool window_open;

};

extern struct m_app app;