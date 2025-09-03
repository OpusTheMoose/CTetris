#pragma once
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#define COLS 10
#define ROWS 20
#define AREA COLS * ROWS

static uint16_t grid[AREA];

#define get_square(row, col) (grid[row * COLS + col])
#define set_square(row, col, val) (grid[row * COLS + col] = val)

#define TETRIS_BAR 0
#define TETRIS_SQUARE 1
#define TETRIS_T 2
#define TETRIS_J 3
#define TETRIS_L 4
#define TETRIS_SKEW 5
#define TETRIS_Z 6

#define EMPTY UINT16_MAX

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
// Implementation details in game_encodePiece
// TODO: Make a 1D array
static const uint16_t PIECE_LOOKUP_TABLE[19][4] = 
{
    {
        0, 1, 2, 3, // TETRIS BAR VERTICAL
    },
    {
        0, 256, 512, 768 // TETRIS BAR HORIZONTAL
    },
    {
        8192, 8193, 8448, 8449 // SQUARE
    },
    {
        16385, 16641, 16897, 16640 // T UP
    },
    {
        16384, 16640, 16896, 16641 // T DOWN
    },
    {
        16384, 16385, 16386, 16641 // T RIGHT
    },
    {
        16640, 16641, 16642, 16385 // T LEFT
    },
    {
       24832, 24833, 24834, 24578 // J UP
    },
    {
            // J DOWN
    }
   
};
static ActivePiece active_piece;
// Create a function that returns the respective piece, plus any optional rotation.

static float timer = 0.0; // Initalize the timer for piece falling.
void game_Init();
uint16_t game_encodePiece(uint8_t type, uint8_t x, uint8_t y);
void game_decodePiece(uint16_t encoded);
void game_spawnNewPiece(int type);
void game_Update(float dt);
void game_Draw(SDL_Renderer* renderer );

void game_PrintGrid();
