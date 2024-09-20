#pragma once
#include <SDL2/SDL.h>
#include <stdbool.h>

struct m_app
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool window_open;

};

extern struct m_app app;