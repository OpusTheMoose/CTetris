#include <SDL2/SDL_image.h>

#include "../include/sprite.h"
#include "../include/app.h"
#include "../include/game.h"
#define ROWS 20
#define COLS 10
#define PLAYER_ID 15


unsigned int num_of_sprites = 0;
unsigned int index1 = 0;
unsigned int index2 = 0;
struct sprite* sprite_list; 


Uint8 sprite_grid[ROWS][COLS] = { 0 };


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
    sprite_list[num_of_sprites - 1].id = 0;

}
void m_update_sprites()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] != 0 && sprite_grid[i][j] == 0)
            {
                m_createSprite(j * 32, i * 32, 32, 32, "include/tile.png" );
                
                sprite_grid[i][j] = 1;
            }
            else if (grid[i][j] == 0 && sprite_grid[i][j] == 1)
            {
                m_remove_sprite(j * 32, i * 32);
                sprite_grid[i][j] = 0;
            }
        }
    }
}
void m_update_player(Uint8 x, Uint8 y, Uint8 Matrix_N, Uint8 *matrix[4])
{
  
    for (int i = 0; i < 4; i++)
    {
        m_remove_sprite_by_id(PLAYER_ID);
    }

    for (int i = 0; i < Matrix_N; i++)
    {
        for (int j = 0; j < Matrix_N; j++)
        {
            if (matrix[j][i] == 1)
            {
                //Should always be pushed at the end of the list.
                m_createSprite((x + i) * 32, (y + j) * 32, 32, 32, "include/tile.png");
                sprite_list[num_of_sprites - 1].id = PLAYER_ID;
            }

        }
    }
  
 
}
void m_remove_sprite_by_id(Uint8 id)
{
    for (int i = 0; i < num_of_sprites; i++)
    {
        if (sprite_list[i].id == id)
        {
            if (sprite_list[i].texture != NULL)
            {
                 SDL_DestroyTexture(sprite_list[i].texture);
                sprite_list[i].texture = NULL;
            }
             for (int j = i; j < num_of_sprites - 1; j++) {
                sprite_list[j] = sprite_list[j + 1];
                }

            num_of_sprites--;  
            if (num_of_sprites == 0)
            {
                SDL_DestroyTexture(sprite_list[0].texture);
                sprite_list[0].texture = NULL;
                break;
            }
            struct sprite *temp = realloc(sprite_list, num_of_sprites * sizeof(struct sprite));
             if (temp != NULL) 
             {
            sprite_list = temp;
            } 
            else {
            printf("ERROR: Failed to Realloc memory. \n");
                
            exit(0);
            }
        }
    }
}
void m_remove_sprite(int x, int y)
{
    
    for (int i = 0; i < num_of_sprites; i++)
    {
        if (sprite_list[i].texture_rect.x == x && sprite_list[i].texture_rect.y == y)
        {
            if (sprite_list[i].texture != NULL)
            {
                 SDL_DestroyTexture(sprite_list[i].texture);
                sprite_list[i].texture = NULL;
            }
             for (int j = i; j < num_of_sprites - 1; j++) {
                sprite_list[j] = sprite_list[j + 1];
                }

            num_of_sprites--;  
            if (num_of_sprites == 0)
            {
                SDL_DestroyTexture(sprite_list[0].texture);
                sprite_list[0].texture = NULL;
                break;
            }
            struct sprite *temp = realloc(sprite_list, num_of_sprites * sizeof(struct sprite));
             if (temp != NULL) 
             {
            sprite_list = temp;
            } 
            else {
            printf("ERROR: Failed to Realloc memory. \n");
                
            exit(0);
            }

        }
    }
}
