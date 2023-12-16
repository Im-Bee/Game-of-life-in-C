#include "Board.h"
#include "GameLogic.h"

#include <windows.h>

#define BOARD_SIZE_W 80
#define BOARD_SIZE_H 16

#define GAME_UPDATE_LATENCY 100

int main()
{
    Board myBoard;
    Board backBoard;

    if (!CreateBoard(BOARD_SIZE_W,
        BOARD_SIZE_H,
        &myBoard))
        return -1;

    if (!CreateBoard(BOARD_SIZE_W,
        BOARD_SIZE_H,
        &backBoard))
        return -1;

    // It does nothing for now
    LoadPlayerInput(&myBoard);

    for (;;)
    {
        ShowBoard(&myBoard);
        UpdateGame(&myBoard, &backBoard);

        Sleep(GAME_UPDATE_LATENCY);
    }

    DisposeBoard(&myBoard);
    DisposeBoard(&backBoard);
}