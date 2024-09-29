#include "../include/game.h"
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <time.h>
#define ACTIVE_SEGMENT 15
#define ROWS 20
#define COLS 10

#define MATRIX_N 4
#define OFFSET_THREE 3
#define OFFSET_FOUR 4

#define STRAIGHT 0
#define SQUARE 1
#define L 2
#define T 3



Uint8 MATRIX_I[MATRIX_N][MATRIX_N] = {{0, 0, 0, 0}, {1, 1, 1, 1}, {0, 0, 0, 0}, {0, 0, 0, 0}};
Uint8 MATRIX_S[MATRIX_N][MATRIX_N] = {{1, 1, 0, 0}, {1, 1, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};
Uint8 MATRIX_L[MATRIX_N][MATRIX_N] = {{0, 1, 0, 0}, {0, 1, 0, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
Uint8 MATRIX_T[MATRIX_N][MATRIX_N] = {{0, 1, 0, 0}, {1, 1, 1, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}};

Uint8 grid[ROWS][COLS] =
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

void rotate90CounterClockwise()
{
      for (int i = 0; i < MATRIX_N / 2; i++) {
        int top = i;
        int bottom = MATRIX_N - 1 - i;
        for (int j = top; j < bottom; j++) {
            int temp = current.matrix[top][j];
            current.matrix[top][j] = current.matrix[j][bottom];
            current.matrix[j][bottom] = current.matrix[bottom][bottom - (j - top)];
            current.matrix[bottom][bottom - (j - top)] = current.matrix[bottom - (j - top)][top];
            current.matrix[bottom - (j - top)][top] = temp;
        }
    }
}
void rotate90Clockwise()
{
 
    // Traverse each cycle
    for (int i = 0; i < MATRIX_N / 2; i++) {
        for (int j = i; j < MATRIX_N - i - 1; j++) {
 
            // Swap elements of each cycle
            // in clockwise direction
            int temp = current.matrix[i][j];
            current.matrix[i][j] = current.matrix[MATRIX_N - 1 - j][i];
            current.matrix[MATRIX_N - 1 - j][i] = current.matrix[MATRIX_N - 1 - i][MATRIX_N - 1 - j];
            current.matrix[MATRIX_N - 1 - i][MATRIX_N - 1 - j] = current.matrix[j][MATRIX_N - 1 - i];
            current.matrix[j][MATRIX_N - 1 - i] = temp;
        }
    }
}

void m_game_start()
{
   
  m_create_piece();

}
int accum = 0;
int yy = 1;

void m_game_update(int dt)
{
    
    accum += dt;
    if (accum >= 100) //every second
    {
        m_check_rows();
        m_drop_piece();
        
        accum = 0;
    }
}
void m_drop_piece()
{
    m_update_player(current.x, current.y, MATRIX_N, current.matrix);
    yy++;
    current.y = yy;

    if (m_is_piece_valid() == false)
    {
        m_game_set_grid_pos(current.x, current.y - 1, 1);
        m_create_piece();
        yy = 0;
    }

}
void m_game_set_grid_pos(Int8 x, Int8 y, Uint8 val)
{
   
    for (int i = 0; i < MATRIX_N; i++)
    {
        for (int j = 0; j < MATRIX_N; j++)
        {
            if (current.matrix[i][j] == 1)
            {
                grid[y + i][x + j] = val;
            }
        }
    }
   
}
void m_create_piece()
{
   unsigned int seed = time(0);
   unsigned int piece = rand_r(&seed) % 4;
    current.y = 0;
    current.id = piece;

    switch (piece)
    {
        case STRAIGHT:
            for (int i = 0; i < MATRIX_N; i++)
            {
                current.matrix[i] = MATRIX_I[i];
            }
            current.x = OFFSET_THREE;
            break;
        case SQUARE:
            for (int i = 0; i < MATRIX_N; i++)
            {
                current.matrix[i] = MATRIX_S[i];
            }
            current.x = OFFSET_FOUR;
            break;
        case L:
            for (int i = 0; i < MATRIX_N; i++)
            {
                current.matrix[i] = MATRIX_L[i];
            }
            current.x = OFFSET_FOUR;
            break;
        case T:
            for (int i = 0; i < MATRIX_N; i++)
            {
                current.matrix[i] = MATRIX_T[i];
            }
            current.x = OFFSET_THREE;
            break;
    }
    m_update_player(current.x, current.y, MATRIX_N, current.matrix);
    m_update_sprites();
}
bool m_is_piece_valid()
{
     for (int i = 0; i < MATRIX_N; i++)
    {
        for (int j = 0; j < MATRIX_N; j++)
        {
            if (current.matrix[i][j] == 1)
            {
               if (i + current.y >= ROWS || j + current.x >= COLS || j + current.x < 0 || grid[current.y + i][current.x + j] == 1)
               {
                return false;
               }
            }
        }
    }
    return true;
}
void m_handle_input(int key )
{
    switch (key)
    {
        case 'd':
            current.x++;
            if (m_is_piece_valid() == false)
            {
                current.x--;
                break;
            }
            break;
        case 'a':
            current.x--;
            if (m_is_piece_valid() == false)
            {
                current.x++;
                break;
            }
            break;
        case 'm':
            if (current.id == SQUARE) break;
            rotate90Clockwise();
            if (m_is_piece_valid() == false)
            {
                rotate90CounterClockwise();
                break;
            }

            break;
        case 'n':
            if (current.id == SQUARE) break;
            rotate90CounterClockwise();
            if (m_is_piece_valid() == false)
            {
                rotate90Clockwise();
                break;
            }
            

            break;
    }
    m_update_player(current.x, current.y, MATRIX_N, current.matrix);
}
void m_check_rows()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 0) break; //If the block is 0, then go to the next row
            if (j == COLS - 1)
            {
                m_clear_rows(i);
                
            }
        }
    }
     m_update_sprites();
}
void m_clear_rows(Uint8 row)
{
    for (int k = 0; k < COLS; k++)
    {
        grid[row][k] = 0;
    }
    for (int i = row - 1; i != 0; i--) 
    {   
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == 1)
            {
                grid[i][j] = 0;
                grid[i + 1][j] = 1;
            }
        }
    }
}