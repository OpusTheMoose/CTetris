#pragma once
#include <SDL2/SDL.h>
#include <stdbool.h>

/*
    TODO
    Move app information to a seperate file. This makes it clearer which file to include
*/ 
static struct m_app
{
    SDL_Window* window;
    SDL_Renderer* renderer;
    bool window_open;

} app;

void m_create_window(unsigned int width, unsigned int height);
void m_render_window();
void m_destroy_window();