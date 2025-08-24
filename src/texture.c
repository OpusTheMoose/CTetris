#include "../include/texture.h"

void texture_AddTexture(const char* texture, SDL_Rect rect)
{
    // Check first if the texture already exists.
    for (size_t i = 0; i < texture_cache_size; i++)
    {
        if (strcmp(texture, textures[i].texture_name) == 0 ) return;
    }
    // Create the texture
    Texture text = 
    {
        .rect = rect,
        .texture_name = texture
    };
    textures[texture_cache_size] = text;
    texture_cache_size++;
   

};