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

    ShowBoard(&myBoard);
    for (;;)
    {
        Sleep(GAME_UPDATE_LATENCY);

        UpdateGame(&myBoard, &backBoard);
        ShowBoard(&myBoard);
    }

    DisposeBoard(&myBoard);
    DisposeBoard(&backBoard);
}