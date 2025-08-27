#include "../include/game.h"

void game_Init()
{
    // Initalize grid values to 0
    for (int i = 0; i < AREA; i++)
    {
        grid[i] = 0;
    }
    uint16_t encode = game_encodePiece(TETRIS_BAR, 10, 20);
    game_decodePiece(encode);
  //  printf("%i \n", encode);

}
uint16_t game_encodePiece(uint8_t type, uint8_t x, uint8_t y)
{
    // Format is like this:
    // 0 0 0 0 0 0 0 0 first 8 bits encode the y position
    // 0 0 0 0 0 Next 5 bits encode the x postion
    // 0 0 0 Last 3 bits encode the position.
    uint16_t encode = 0;
    encode |= y; // Low byte
    encode |= (x << 8); // High byte
   // encode |= (7 << 13); // Mask the last 3 digits to be 1 (111 in binary or 7)
    encode |= (type << 13); // Now mask the last 3 bits
    return encode;
}
void game_decodePiece(uint16_t encoded)
{
    uint8_t y = (encoded & UINT8_MAX);
    uint8_t x = (encoded >> 8) & 31; //2^5 - 1
    uint8_t ID = (encoded >> 13) & 7;
    printf("x: %i, y: %i, ID: %i \n", x, y, ID);
}
void game_spawnNewPiece(int type)
{
    switch (type)
    {
        case TETRIS_BAR:
            active_piece.tiles[0].x = 3;
            active_piece.tiles[0].y = 0;

    }
}
// For debugging
void game_PrintGrid()
{
    for (int i = 0; i < AREA; i++)
    {
        if (i % COLS == 0)
        {
            printf("\n");
        }
        printf("%i ", grid[i]);
    }
    printf("\n");
}