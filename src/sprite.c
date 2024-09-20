#include <SDL2/SDL_image.h>

#include "../include/sprite.h"
#include "../include/app.h"

struct sprite list_of_sprites[5];
void m_createSprite(float w, float h, const char* file)
{
    SDL_Texture *tex = IMG_LoadTexture(app.renderer, file);
    if (tex == NULL)
    {
        printf("ERROR: Failed to create texture: ");
        printf("%s", SDL_GetError());
        exit(0); //Try to have a deafult texture loaded just in case.
    }
    SDL_Rect texture_rect;
    texture_rect.x = 0;
    texture_rect.y = 0;
    texture_rect.h = h;
    texture_rect.w = w;
    struct sprite new_spirte = {tex, texture_rect};
    list_of_sprites[0] = new_spirte;

    return;
    
}
