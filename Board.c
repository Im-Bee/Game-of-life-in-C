#include "Board.h"
#include "Typedefs.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CreateBoard(const int width, const int height, Board* b)
{
    b->Height = height;
    b->Width = width;

    uint16_t** tmpContentPtr = (unsigned char**) malloc(width * height * sizeof(unsigned char*));

    // Check if malloc succeded
    if (!tmpContentPtr)
        return 0;

    for (int i = 0; i < height; i++)
    {
        tmpContentPtr[ i ] = (unsigned char*) malloc(width * sizeof(unsigned char));

        // Check if malloc succeded
        if (!tmpContentPtr[ i ])
            return 0;

        for (int j = 0; j < width; j++)
            tmpContentPtr[ i ][ j ] = 0;
    }

    // DEBUG
    {
        tmpContentPtr[ 2 ][ 2 ] = 1;
        tmpContentPtr[ 2 ][ 4 ] = 1;
        tmpContentPtr[ 3 ][ 3 ] = 1;
        tmpContentPtr[ 3 ][ 1 ] = 1;
        tmpContentPtr[ 2 ][ 2 ] = 1;
        tmpContentPtr[ 2 ][ 3 ] = 1;
        tmpContentPtr[ 2 ][ 4 ] = 1;
        tmpContentPtr[ 3 ][ 2 ] = 1;
        tmpContentPtr[ 3 ][ 3 ] = 1;
        tmpContentPtr[ 4 ][ 2 ] = 1;
        tmpContentPtr[ 4 ][ 4 ] = 1;
        tmpContentPtr[ 3 ][ 5 ] = 1;
        tmpContentPtr[ 3 ][ 4 ] = 1;
        tmpContentPtr[ 2 ][ 5 ] = 1;
        tmpContentPtr[ 2 ][ 6 ] = 1;
    }

    b->Content = tmpContentPtr;

    return 1;
}

int LoadPlayerInput(Board* b)
{
    return 0;
}

void ShowBoard(Board* b)
{
    // Clear the terminal
    system("cls");

    unsigned char boardCharBuff[ 2048 ] = { 0 };

    int charIndx = 0;
    for (int i = 0; i < b->Height; i++)
    {
        for (int j = 0; j < b->Width; j++)
        {
            unsigned char shownChar;

            if (b->Content[ i ][ j ])
                shownChar = FULL_BLOCK_CHAR;
            else
                shownChar = EMPTY_BLOCK_CHAR;

            // printf("%c", shownChar);
            boardCharBuff[ charIndx++ ] = shownChar;
        }
        
        // printf("\n");
        boardCharBuff[ charIndx++ ] = '\n';
    }

    boardCharBuff[ charIndx ] = '\0';
    printf("%s", boardCharBuff);
}

void DisposeBoard(Board* b)
{
    for (int i = 0; i < b->Height; i++)
        free(b->Content[ i ]);

    free(b->Content);
}
