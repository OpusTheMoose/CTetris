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
    //
    game_encodePiece(TETRIS_J, 1, 0);
    game_encodePiece(TETRIS_J, 1, 1);
    game_encodePiece(TETRIS_J, 1, 2);
    game_encodePiece(TETRIS_J, 0, 2);
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
    encode |= (type << 13); // Now mask the last 3 bits
    printf("Encode: %i \n", encode);
    return encode;
}
void game_decodePiece(uint16_t encoded)
{
    uint8_t col = (encoded & UINT8_MAX);
    uint8_t row = (encoded >> 8) & 31; //2^5 - 1
    uint8_t ID = (encoded >> 13) & 7;
    printf("%i , %i, %i \n", row, col, ID);
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
        case TETRIS_SQUARE:
            piece_data[0] = PIECE_LOOKUP_TABLE[2][0];
            piece_data[1] = PIECE_LOOKUP_TABLE[2][1];
            piece_data[2] = PIECE_LOOKUP_TABLE[2][2];
            piece_data[3] = PIECE_LOOKUP_TABLE[2][3];
            break;
        case TETRIS_T:
            piece_data[0] = PIECE_LOOKUP_TABLE[3][0];
            piece_data[1] = PIECE_LOOKUP_TABLE[3][1];
            piece_data[2] = PIECE_LOOKUP_TABLE[3][2];
            piece_data[3] = PIECE_LOOKUP_TABLE[3][3];
            break;
        case TETRIS_J:
            piece_data[0] = PIECE_LOOKUP_TABLE[7][0];
            piece_data[1] = PIECE_LOOKUP_TABLE[7][1];
            piece_data[2] = PIECE_LOOKUP_TABLE[7][2];
            piece_data[3] = PIECE_LOOKUP_TABLE[7][3];
            break;
        default:
            printf("ERROR: Invalid type passed in spawnNewPiece \n");
            break;

    }
    // Write the piece lookup data to the active tiles. 
    for (int i = 0; i < 4; i++)
    {
        const uint16_t id = decodeID(piece_data[i]);
        const uint16_t y = decodeCol(piece_data[i]);
        const uint16_t x = decodeRow(piece_data[i]);
     
        active_piece.tiles[i].ID = id;
        active_piece.tiles[i].x = x;
        active_piece.tiles[i].y = y;
        // set_square(y, x, id);
    }
    
   
}
void game_addTileToGrid(Tile tile)
{
   // uint16_t piece = (tile.ID << 13) || (tile.x << 8) || (tile.y);
    set_square(tile.x, tile.y, tile.ID);
}
bool bottom_intersection()
{
    return  active_piece.tiles[0].y >= ROWS || 
            active_piece.tiles[1].y >= ROWS ||
            active_piece.tiles[2].y >= ROWS ||
            active_piece.tiles[3].y >= ROWS;

}
void game_Update(float dt)
{
    timer += dt;
    // Arbiturary threshold for now
    if (timer > 0.5) timer = 0;
    else return;

    for (int i = 0; i < 4; i++)
    {
        active_piece.tiles[i].y += 1;
    }
    // Undo the last section (something something command design pattern)
    if (bottom_intersection())
    {
        // Undo
        const uint16_t id = active_piece.tiles[0].ID;
        for (int i = 0; i < 4; i++)
        {
            active_piece.tiles[i].y -= 1;
             // Write to the grid. These tiles are now effectively "static".
            set_square(active_piece.tiles[i].y, active_piece.tiles[i].x, id);
            game_PrintGrid();
        }
       

    }
    
}
void game_Draw(SDL_Renderer* renderer )
{
    Texture* piece = texture_GetTexture(0);
   
    for (int i = 0; i < 4; i++) // gcc will probably optimize this out
    {
        // Flipped x and y, since im doing row/columns
        SDL_Rect rect = {
            .x = (float)active_piece.tiles[i].x * 32.0,
            .y = (float)active_piece.tiles[i].y * 32.0,
            .w = 32.0,
            .h = 32.0
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