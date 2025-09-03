#include "../include/texture.h"

void texture_Init(SDL_Renderer* renderer_)
{
    // Initialize SDL2_image
    if (IMG_Init(IMG_INIT_PNG) == 0) {
        printf("Failed to initialize SDL2_image: %s\n", IMG_GetError());
        return;
    }
    texture_renderer = renderer_;
}
void texture_AddTexture(const char* texture, SDL_Rect rect)
{
    // Check first if the texture already exists.
    for (size_t i = 0; i < texture_cache_size; i++)
    {
        if (strcmp(texture, textures[i].texture_name) == 0 ) return;
    }
    SDL_Texture* text_ = IMG_LoadTexture(texture_renderer, texture);
    if (text_ == NULL)
    {
        printf("ERROR: Failed to create texture, %s", SDL_GetError());
    }
    // Create the texture
    Texture text = 
    {
        .rect = rect,
        .text = text_,
        .texture_name = texture
    };
    textures[texture_cache_size] = text;
    texture_cache_size++;
   

};
Texture* texture_GetTexture(uint8_t textureID)
{
    if (textureID > texture_cache_size)
    {
        printf("ID out of range, unable to retrive texture");
    }
    return &textures[textureID];

}