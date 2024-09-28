#include "../include/game.h"
#include "../include/piece_info.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>
#define ACTIVE_SEGMENT 15
#define ROWS 20
#define COLS 10

Uint8 MATRIX_I[4][4] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};

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

Player current;

void rotate90Clockwise()
{
 
    // Traverse each cycle
    for (int i = 0; i < current.matrix_N / 2; i++) {
        for (int j = i; j < current.matrix_N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = current.matrix[i][j];
            current.matrix[i][j] = current.matrix[current.matrix_N - 1 - j][i];
            current.matrix[current.matrix_N - 1 - j][i] = current.matrix[current.matrix_N - 1 - i][current.matrix_N - 1 - j];
            current.matrix[current.matrix_N - 1 - i][current.matrix_N - 1 - j] = current.matrix[j][current.matrix_N - 1 - i];
            current.matrix[j][current.matrix_N - 1 - i] = temp;
        }
    }
     m_update_player(current.x, current.y, current.matrix_N, current.matrix);
}

void m_set_piece(Uint8 x, Uint8 y, Uint8 id, Uint8 matrix_N)
{
    current.x = x;
    current.y = y;
    current.id = id;
    current.matrix_N = matrix_N;
    for (int i = 0; i < matrix_N; i++)
    {
        current.matrix[i] = MATRIX_I[i];
    }
    
}
void m_game_start()
{
   unsigned int seed = time(0);
   unsigned int piece = rand_r(&seed) % 5;

   m_set_piece(3, 0, 0, 4);
  
  //m_update_player(current.x, current.y, current.matrix_N, current.matrix);

}
int accum = 0;
int yy = 1;

void m_game_update(int dt)
{
    accum += dt;
    if (accum >= 1000) //every second
    {
        
        m_set_piece(current.x, yy, current.id, 4);
        yy++;
        m_update_player(current.x, current.y, current.matrix_N, current.matrix);

        accum = 0;
    }
    
    
}
void m_game_set_grid_pos(Uint8 x, Uint8 y, Uint8 id, Uint8 dir, Uint8 val)
{
   
    for (int i = 0; i < current.matrix_N; i++)
    {
        for (int j = 0; j < current.matrix_N; j++)
        {
            if (current.matrix[i][j] == 1)
            {
                grid[y + i][x + j] = val;
            }
        }
    }
   
    
}
bool m_is_piece_valid(Uint8 x, Uint8 y, Uint8 dir)
{
    return true;
}
void m_rotate_right()
{

    rotate90Clockwise();
}