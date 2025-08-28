#include "../include/game.h"

void game_Init()
{
    // Initalize grid values to 0
    for (int i = 0; i < AREA; i++)
    {
        grid[i] = 0;
    }
    uint16_t encode = game_encodePiece(TETRIS_BAR, 0, 3);
    printf("encoded: %i \n", encode);
    game_decodePiece(encode);
  //  printf("%i \n", encode);

}
uint16_t game_encodePiece(uint8_t type, uint8_t row, uint8_t col)
{
    // Format is like this:
    // 0 0 0 0 0 0 0 0 first 8 bits encode the y position
    // 0 0 0 0 0 Next 5 bits encode the x postion
    // 0 0 0 Last 3 bits encode the position.
    uint16_t encode = 0;
    encode |= col; // Low byte
    encode |= (row << 8); // High byte
   // encode |= (7 << 13); // Mask the last 3 digits to be 1 (111 in binary or 7)
    encode |= (type << 13); // Now mask the last 3 bits
    return encode;
}
void game_decodePiece(uint16_t encoded)
{
    uint8_t col = (encoded & UINT8_MAX);
    uint8_t row = (encoded >> 8) & 31; //2^5 - 1
    uint8_t ID = (encoded >> 13) & 7;
    printf("row: %i, col: %i, ID: %i \n", row, col, ID);
}
void game_spawnNewPiece(int type)
{
    switch (type)
    {
        case TETRIS_BAR:
         //   uint16_t piece_id[4] = PIECE_LOOKUP_TABLE[0];

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