#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdint.h>
#include <SDL_image.h>


#define TEXTURE_LIMIT 255

typedef struct
{
    SDL_Rect rect;
    SDL_Texture* text;
    const char* texture_name;
} Texture;

static size_t texture_cache_size = 0;
static Texture textures[TEXTURE_LIMIT];
// This is bad for a lot of reasons, but I dont understand why IMG_Load takes renderer.
// Just treat this as readonly
static SDL_Renderer* texture_renderer;

void texture_AddTexture(const char* file, SDL_Rect rect);
Texture* texture_GetTexture(uint8_t textureID);
void texture_Init(SDL_Renderer* renderer_);