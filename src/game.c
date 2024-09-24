#include "../include/game.h"
#include "../include/piece_info.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>
#define ACTIVE_SEGMENT 15
#define ROWS 20
#define COLS 10

Uint8 grid[20][10] =
{
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},


};

struct current_piece{
    Uint8 x;
    Uint8 y;
    Uint8 id;
    Uint8 dir;
} current;

void m_set_piece(Uint8 x, Uint8 y, Uint8 id, Uint8 dir)
{
    current.x = x;
    current.y = y;
    current.id = id;
    current.dir = dir;
}
void m_game_start()
{
   unsigned int seed = time(0);
   unsigned int piece = rand_r(&seed) % 5;

   m_set_piece(3, 0, 0, 0);
   m_game_set_grid_pos(current.x, current.y, current.id, current.dir, 1);

}
int accum = 0;
int yy = 1;
void m_game_update(int dt)
{
    
    accum += dt;
    if (accum == 1000) //every second
    {
        m_game_set_grid_pos(current.x, current.y, current.id, current.dir, 0);
        m_game_set_grid_pos(current.x, yy, 0, 0, 1);
        m_set_piece(current.x, yy, current.id, current.dir);
        yy++;
        accum = 0;
    }
    
    
}
void printBoard()
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
}
void m_game_set_grid_pos(Uint8 x, Uint8 y, Uint8 id, Uint8 dir, Uint8 val)
{
    
    int blocks_rotation = ROTATION_ARRAYS[(id * 4) + dir];
         
    int row = 0, col = 0;
    for(int bit = 0x8000; bit > 0; bit = bit >> 1)
    {
        if (blocks_rotation & bit)
        {
            grid[y + row][x + col] = val;
        }
        if (++col == 4)
        {
            col = 0;
            ++row;
        }
        
    }
    printBoard();
   
    
}
bool m_is_piece_valid(Uint8 x, Uint8 y, Uint8 dir)
{

}
