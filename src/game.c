#include "../include/game.h"
#include "../include/texture.h"

#define decodeID(x) (x >> 13) & 7
#define decodeRow(x) (x >> 8) & 31
#define decodeCol(x) (x & UINT8_MAX);
void game_Init()
{
    // Initalize grid values to 0
    for (int i = 0; i < AREA; i++)
    {
        grid[i] = EMPTY;
    }
    uint16_t encode = game_encodePiece(TETRIS_BAR, 0, 3);
    game_decodePiece(encode);
    SDL_Rect text_rect = {.x = 0, .y = 0, .w = 16, .h = 16};
    texture_AddTexture("include/tile.png", text_rect );

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
}
void game_spawnNewPiece(int type)
{
    uint16_t piece_data[4];
    switch (type)
    {
        case TETRIS_BAR:
            piece_data[0] = PIECE_LOOKUP_TABLE[0][0];
            piece_data[1] = PIECE_LOOKUP_TABLE[0][1];
            piece_data[2] = PIECE_LOOKUP_TABLE[0][2];
            piece_data[3] = PIECE_LOOKUP_TABLE[0][3];
            break;
        default:
            printf("ERROR: Invalid type passed in spawnNewPiece \n");
            break;

    }
    // Write the piece lookup data to the active tiles. 
    for (int i = 0; i < 4; i++)
    {
        const uint16_t id = decodeID(piece_data[i]);
        const uint16_t x = decodeCol(piece_data[i]);
        const uint16_t y = decodeRow(piece_data[i]);
     
        active_piece.tiles[i].ID = id;
        active_piece.tiles[i].x = x;
        active_piece.tiles[i].y = y;
        set_square(x, y, id);
    }
    
   
}
void game_addTileToGrid(Tile tile)
{
   // uint16_t piece = (tile.ID << 13) || (tile.x << 8) || (tile.y);
    set_square(tile.x, tile.y, tile.ID);
}
void game_Draw(SDL_Renderer* renderer )
{
    Texture* piece = texture_GetTexture(0);
   
    for (int i = 0; i < 4; i++) // gcc will probably optimize this out
    {
        SDL_Rect rect = {
            .x = (float)active_piece.tiles[i].x * 16.0,
            .y = (float)active_piece.tiles[i].y * 16.0,
            .w = 16.0,
            .h = 16.0
        };
     //   printf("%f \n", (float)active_piece.tiles[i].x * 16.0);
        SDL_RenderCopy(renderer, piece->text, NULL, &rect);
    }
}
// For debugging
void game_PrintGrid()
{
    for (uint16_t i = 0; i < AREA; i++)
    {
        if (i % COLS == 0)
        {
            printf("\n");
        }
        if (grid[i] == UINT16_MAX) printf("-1");
        else     printf("%i ", grid[i]);
        
    
    }
    printf("\n");
}