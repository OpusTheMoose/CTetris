#include "../include/game.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>
#define ACTIVE_SEGMENT 15
void m_game_start()
{
   unsigned int seed = time(0);
   unsigned int piece = rand_r(&seed) % 5;
   m_createTetromino(128, 0, 32, 32, "include/tile.png", piece);
    m_game_spawn_tetromino(piece);
}
int accum = 0;
void m_game_update(int dt)
{
    
    
    accum += dt;
    if (accum == 1000) //every second
    { 
        printf("%d \n", accum);
        m_UpdateActivePiece(0, 32);
        accum = 0;
        //printf("%d \n", accum);
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
}
void m_game_spawn_tetromino(Uint8 id)
{
    switch (id)
    {
    case 0: //Straight
        grid[0][3] = ACTIVE_SEGMENT;
        grid[0][4] = ACTIVE_SEGMENT;
        grid[0][5] = ACTIVE_SEGMENT;
        grid[0][6] = ACTIVE_SEGMENT;
        printBoard();
        break;
    case 1: //Square
        grid[0][4] = ACTIVE_SEGMENT;
        grid[0][5] = ACTIVE_SEGMENT;
        grid[1][4] = ACTIVE_SEGMENT;
        grid[1][5] = ACTIVE_SEGMENT;
        printBoard();
        break;
    case 2: //T
        grid[0][4] = ACTIVE_SEGMENT;
        grid[0][5] = ACTIVE_SEGMENT;
        grid[0][6] = ACTIVE_SEGMENT;
        grid[1][5] = ACTIVE_SEGMENT;
        printBoard();
        break;
    case 3: //L
        grid[0][4] = ACTIVE_SEGMENT;
        grid[0][5] = ACTIVE_SEGMENT;
        grid[0][6] = ACTIVE_SEGMENT;
        grid[1][4] = ACTIVE_SEGMENT;
        printBoard();
        break;
        
    default:
        break;
    }
}
