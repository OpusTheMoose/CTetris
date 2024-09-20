#include <SDL2/SDL.h>
#pragma once

typedef unsigned short int Grid_Pos;
extern struct sprite* sprite_list;
extern size_t num_of_sprites;

struct sprite{
    SDL_Texture *texture;
    SDL_Rect texture_rect;
};

struct tetromino{
    struct sprite* spite_data[4];
    //grid positions
    Grid_Pos x;
    Grid_Pos y; 

};


struct sprite* m_createSprite(float x, float y, float w, float h, const char* file);
void m_createTetromino(float x, float y, float w, float h, const char* file, unsigned int piece_name);