#pragma once
#include <stdio.h>
#include <stdint.h>

#define COLS 10
#define ROWS 20
#define AREA COLS * ROWS

static uint8_t grid[AREA];

#define get_square(row, col) (grid[row * COLS + col])
#define set_square(row, col, val) (grid[row * COLS + col] = val)

#define TETRIS_BAR 0
#define TETRIS_SQUARE 1
#define TETRIS_T 2
#define TETRIS_J 3
#define TETRIS_L 4
#define TETRIS_SKEW 5
#define TETRIS_Z 6

// PIECES L AND J HAVE 4 ROTATIONS

typedef struct 
{
    uint8_t ID;
    uint8_t x, y;
} Tile;

// Create a function that returns the respective piece, plus any optional rotation.


void game_Init();

void game_PrintGrid();
