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

typedef struct 
{
    Tile tiles[4];
} ActivePiece;

// 19 possible rotations of the tetrominos. Each one has 4 tiles.
// static const uint16_t PIECE_LOOKUP_TABLE[19][4] = 
// {
//     {

//     }
// };
static ActivePiece active_piece;
// Create a function that returns the respective piece, plus any optional rotation.


void game_Init();
uint16_t game_encodePiece(uint8_t type, uint8_t x, uint8_t y);
void game_decodePiece(uint16_t encoded);
void game_spawnNewPiece(int type);

void game_PrintGrid();
