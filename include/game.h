#include <stdbool.h>
#include "sprite.h"
#pragma once
#define Int8 int8_t
#define ROWS 20
#define COLS 10

extern int accum;

enum GAME {
    GAME_ACTIVE,
    GAME_OVER
};

struct player{
    Int8 x;
    Int8 y;
    Uint8 id;
    Uint8 *matrix[4];
};
typedef struct player Player;
typedef enum GAME GAME;
//extern struct player current;
extern Uint8 grid[ROWS][COLS];
extern GAME game_state;

void rotate90CounterClockwise();
void rotate90Clockwise();
void m_game_start();
void m_game_update(int dt);
void m_drop_piece();
void m_game_set_grid_pos(Int8 x, Int8 y, Uint8 val);
bool m_is_piece_valid();
void m_handle_input(int key );
void m_create_piece();
void m_check_rows();
void m_clear_rows(Uint8 row);
void m_game_over();