#include <SDL2/SDL.h>
#pragma once

extern struct sprite* sprite_list;
extern unsigned int num_of_sprites;
extern unsigned int index1;
extern unsigned int index2;


struct sprite{
    SDL_Texture *texture;
    SDL_Rect texture_rect;
};



void m_createSprite(float x, float y, float w, float h, const char* file);
void m_createTetromino(float x, float y, float w, float h, const char* file, unsigned int piece_name);
void m_UpdateActivePiece(float x, float y);
void m_game_spawn_tetromino(Uint8 id);