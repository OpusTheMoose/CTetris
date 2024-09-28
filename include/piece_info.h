#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#pragma once


/*
8   4   2   1
0   0   0   0  0xa000
0   0   0   0  0x0b00
0   0   0   0  0x00c0
0   0   0   0  0x000d
*/

//Values / system comes from https://codeincomplete.com/articles/javascript-tetris/. HUGE HELP!
// #define NUM_OF_PIECES 1

// #define I_PIECE_ID 0
// #define I_ROTATION_0 0x0F00
// #define I_ROTATION_1 0x2222
// #define I_ROTATION_2 0x00F0
// #define I_ROTATION_3 0x4444

// static int ROTATION_ARRAYS[4 * NUM_OF_PIECES] = {I_ROTATION_0, I_ROTATION_1, I_ROTATION_2, I_ROTATION_3};

extern Uint8 MATRIX_I[4][4]; 




void fillCell(Uint8 x, Uint8 y, Uint8 dir, Uint8 blocks_type);