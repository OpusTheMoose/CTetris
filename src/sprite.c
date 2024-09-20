#include <SDL2/SDL_image.h>

#include "../include/sprite.h"
#include "../include/app.h"


size_t num_of_sprites = 0;
struct sprite* sprite_list; 
struct sprite* m_createSprite(float x, float y, float w, float h, const char* file)
{
   
    SDL_Texture *tex = IMG_LoadTexture(app.renderer, file);
    if (tex == NULL)
    {
        printf("ERROR: Failed to create texture: ");
        printf("%s", SDL_GetError());
        exit(0); //Try to have a deafult texture loaded just in case.
    }
    SDL_Rect texture_rect;
    texture_rect.x = x;
    texture_rect.y = y;
    texture_rect.h = h;
    texture_rect.w = w;

    num_of_sprites++;
    sprite_list = realloc(sprite_list, num_of_sprites * sizeof(struct sprite));
    sprite_list[num_of_sprites - 1].texture = tex;
    sprite_list[num_of_sprites - 1].texture_rect = texture_rect;

    return &sprite_list[num_of_sprites - 1];
    
}
/*
Creates a tetromino consisting of 4 sprites. w h just controls the size of each individual sprite. x, y is the center.
File is just the path to the piece sprite texture. 
Piece name is 0-4:
0 - Straight
1 - Square
2 - T
3 - L
4 - Skew
*/
void m_createTetromino(float x, float y, float w, float h, const char* file, unsigned int piece_name)
{
    struct tetromino active_piece;
    switch (piece_name)
    {
        case 0:
            active_piece.spite_data[0] = m_createSprite(x, y, w, h, file);
            active_piece.spite_data[1] = m_createSprite(x + w, y, w, h, file);
            active_piece.spite_data[2] = m_createSprite(x + (2 * w), y, w, h, file);
            active_piece.spite_data[3] = m_createSprite(x + (3 * w), y, w, h, file);
            break;
        case 1:
            active_piece.spite_data[0] = m_createSprite(x, y, w, h, file);
            active_piece.spite_data[1] = m_createSprite(x + w, y, w, h, file);
            active_piece.spite_data[2] = m_createSprite(x, y + h, w, h, file);
            active_piece.spite_data[3] = m_createSprite(x + w, y + h, w, h, file);
            break;
        case 2:
            active_piece.spite_data[0] = m_createSprite(x, y, w, h, file);
            active_piece.spite_data[1] = m_createSprite(x - w, y, w, h, file);
            active_piece.spite_data[2] = m_createSprite(x + w, y, w, h, file);
            active_piece.spite_data[3] = m_createSprite(x, y + h, w, h, file);
            break;
        case 3:
            active_piece.spite_data[0] = m_createSprite(x, y, w, h, file);
            active_piece.spite_data[1] = m_createSprite(x, y + h, w, h, file);
            active_piece.spite_data[2] = m_createSprite(x, y + (2 * h), w, h, file);
            active_piece.spite_data[3] = m_createSprite(x + w, y + (2 * h), w, h, file);
            break;
        case 4:
            active_piece.spite_data[0] = m_createSprite(x, y, w, h, file);
            active_piece.spite_data[1] = m_createSprite(x - w, y, w, h, file);
            active_piece.spite_data[2] = m_createSprite(x, y + h, w, h, file);
            active_piece.spite_data[3] = m_createSprite(x + w, y + h, w, h, file);
            break;

        default:
            printf("ERROR: Invalid tetromino ID \n");
            break;

    }
}