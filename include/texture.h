#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include <SDL_image.h>


#define TEXTURE_LIMIT 255

typedef struct
{
    SDL_Rect rect;
    const char* texture_name;
} Texture;

static size_t texture_cache_size = 0;
static Texture textures[TEXTURE_LIMIT];

void texture_AddTexture(const char* file, SDL_Rect rect);