#include "../include/game.h"

void game_Init()
{
    // Initalize grid values to 0
    for (int i = 0; i < AREA; i++)
    {
        grid[i] = 0;
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