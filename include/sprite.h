#include <SDL2/SDL.h>
#pragma once

extern struct sprite* sprite_list;
extern unsigned int num_of_sprites;
extern unsigned int index1;
extern unsigned int index2;


struct sprite{
    SDL_Texture *texture;
    SDL_Rect texture_rect;
    Uint8 id;
};

void m_update_player(Uint8 x, Uint8 y, Uint8 Matrix_N, Uint8 *matrix[4]);
void m_createSprite(float x, float y, float w, float h, const char* file);
void m_update_sprites();
void m_remove_sprite_by_id(Uint8 id);
void m_remove_sprite(int x, int y);
