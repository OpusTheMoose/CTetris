#include <SDL2/SDL_image.h>

#include "../include/sprite.h"
#include "../include/app.h"


unsigned int num_of_sprites = 0;
unsigned int index1 = 0;
unsigned int index2 = 0;
struct sprite* sprite_list; 
struct sprite* temp[4]; 

void m_createSprite(float x, float y, float w, float h, const char* file)
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
    struct sprite *temp = realloc(sprite_list, num_of_sprites * sizeof(struct sprite));
    if (temp == NULL)
    {
        printf("ERROR: Failed to allocate memory for sprite. \n");
        exit(0);
    }
    else
    {
        sprite_list = temp;
    }

    sprite_list[num_of_sprites - 1].texture = tex;
    sprite_list[num_of_sprites - 1].texture_rect.x = x;
    sprite_list[num_of_sprites - 1].texture_rect.y = y;
    sprite_list[num_of_sprites - 1].texture_rect.w = w;
    sprite_list[num_of_sprites - 1].texture_rect.h = h;

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
    index1 = num_of_sprites;
    switch (piece_name)
    {
        
        case 0:
          
            m_createSprite(x, y, w, h, file);
            m_createSprite(x + w, y, w, h, file);
            m_createSprite(x + (2 * w), y, w, h, file);
            m_createSprite(x + (3 * w), y, w, h, file);
           
            break;
      
        case 1:
             m_createSprite(x, y, w, h, file);
             m_createSprite(x + w, y, w, h, file);
             m_createSprite(x, y + h, w, h, file);
             m_createSprite(x + w, y + h, w, h, file);
            break;
        case 2:
            m_createSprite(x, y, w, h, file);
            m_createSprite(x - w, y, w, h, file);
            m_createSprite(x + w, y, w, h, file);
            m_createSprite(x, y + h, w, h, file);
            break;
        case 3:
           m_createSprite(x, y, w, h, file);
           m_createSprite(x, y + h, w, h, file);
           m_createSprite(x, y + (2 * h), w, h, file);
           m_createSprite(x + w, y + (2 * h), w, h, file);
            break;
        case 4:
           m_createSprite(x, y, w, h, file);
           m_createSprite(x - w, y, w, h, file);
           m_createSprite(x, y + h, w, h, file);
           m_createSprite(x + w, y + h, w, h, file);
            break;

        default:
            printf("ERROR: Invalid tetromino ID \n");
            break;

    }
     index2 = num_of_sprites;
    

    
}
/*
Update the sprite positions of the piece.
Adds the VALUES PASSED IN, it does NOT set the position.

*/
void m_UpdateActivePiece(float x, float y)
{
  
    for (int i = index1; i < index2; i++)
    {
        sprite_list[i].texture_rect.x += x;
        sprite_list[i].texture_rect.y += y;
    }

    
 
}