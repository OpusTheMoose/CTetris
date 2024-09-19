#include "../include/sprite.h"
#define STB_IMAGE_IMPLEMENTATION
#include "../include/stb_image.h"

static SDL_Texture* m_createTexture(const char* file_path)
{
    SDL_Surface* surface;
    int width, height, nrChannels;
    surface->pixels = stbi_load(file_path, &width, &height, &nrChannels, 0 );
    surface->w = width;
    surface->h = height;
    //surface->format = nrChannels;

    SDL_Texture* tex = SDL_CreateTextureFromSurface(app.renderer, surface);
    if (tex == NULL)
    {
        printf("ERROR: Failed to create texture: ");
        printf("%s", SDL_GetError());
        exit(0); //Try to have a deafult texture loaded just in case.
    }
    return tex;
}
void m_CreateSprite(float w, float h, const char* file)
{
    m_createTexture(file);
}