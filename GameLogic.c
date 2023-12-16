#include "GameLogic.h"

#include <stdint.h>
#include <stdbool.h>

void UpdateGame(Board* main, Board* dummy)
{
    for (int i = 0; i < main->Height; i++)
    {
        for (int j = 0; j < main->Width; j++)
        {
            // Load values
            const uint16_t curCellVal = main->Content[ i ][ j ];
            uint16_t neighboursValues = 0;

            bool up = ( i - 1 ) >= 0,
                down = ( i + 1 ) < main->Height,
                left = ( j - 1 ) >= 0,
                right = ( j + 1 ) < main->Width;

            // Normal
            if (up)
                neighboursValues += main->Content[ i - 1 ][ j ];

            if (down)
                neighboursValues += main->Content[ i + 1 ][ j ];

            if (left)
                neighboursValues += main->Content[ i ][ j - 1 ];

            if (right)
                neighboursValues += main->Content[ i ][ j + 1 ];

            // Diagonal
            if (up && left)
                neighboursValues += main->Content[ i - 1 ][ j - 1 ];

            if (up && right)
                neighboursValues += main->Content[ i - 1 ][ j + 1 ];

            if (down && left)
                neighboursValues += main->Content[ i + 1 ][ j - 1 ];

            if (down && right)
                neighboursValues += main->Content[ i + 1 ][ j + 1 ];

            // Check to what value update the current cell
            if (curCellVal == 1 &&
                neighboursValues < 2)
            {
                dummy->Content[ i ][ j ] = 0;
                continue;
            }

            if (curCellVal == 1 &&
                ( neighboursValues == 2 || neighboursValues == 3 ))
            {
                dummy->Content[ i ][ j ] = 1;
                continue;
            }

            if (curCellVal == 1 &&
                neighboursValues > 3)
            {
                dummy->Content[ i ][ j ] = 0;
                continue;
            }

            if (curCellVal == 0 &&
                neighboursValues == 3)
            {
                dummy->Content[ i ][ j ] = 1;
                continue;
            }

            dummy->Content[ i ][ j ] = 0;
        }
    }

    // Switch updated board with main board
    unsigned char** tmpContentPtr = main->Content;
    main->Content = dummy->Content;
    dummy->Content = tmpContentPtr;
}
