#include <SDL2/SDL.h>
#pragma once

struct sprite{
    SDL_Texture *texture;
    SDL_Rect texture_rect;
};

extern struct sprite list_of_sprites[5];

void m_createSprite(float w, float h, const char* file);