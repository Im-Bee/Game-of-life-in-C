#include "Board.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define FULL_BLOCK_CHAR 178

int CreateBoard(const int width, const int height, Board* b)
{
    ( *b ).Height = height;
    ( *b ).Width = width;

    unsigned char** tmpContentPtr = (unsigned char**) malloc(height * sizeof(unsigned char*));

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
            tmpContentPtr[ i ][ j ] = FULL_BLOCK_CHAR;
    }

    ( *b ).Content = tmpContentPtr;

    return 1;
}

void ShowBoard(Board* b)
{
    Sleep(400);    
    
    // Clear the terminal
    system("cls");

    for (int i = 0; i < ( *b ).Height; i++)
    {
        for (int j = 0; j < ( *b ).Width; j++)
            printf("%c", (*b).Content[i][j]);

        printf("\n");
    }
}

void DisposeBoard(Board* b)
{
    for (int i = 0; i < ( *b ).Height; i++)
        free(( *b ).Content[ i ]);

    free(( *b ).Content);
}
