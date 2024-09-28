#include <stdbool.h>
#include "sprite.h"
#pragma once
#define Int8 int8_t

extern int accum;
/*
Inital coordinates for straight
(defined y1, x1)
[0, 0]
[0, 1]
[0, 2]
[0, 3]
*/

/*
Inital coordinates for square
[0, 0]
[0, 1]
[1, 0]
[1, 1]
*/
struct player{
    Int8 x;
    Int8 y;
    Uint8 id;
    Uint8 *matrix[4];
};
typedef struct player Player;
//extern struct player current;
extern Uint8 grid[20][10];

void rotate90CounterClockwise();
void rotate90Clockwise();
void m_game_start();
void m_game_update(int dt);
void m_game_set_grid_pos(Uint8 x, Uint8 y, Uint8 id, Uint8 dir, Uint8 val);
bool m_is_piece_valid();
void m_handle_input(int key );
void m_create_piece();
