#include "Board.h"

#define BOARD_SIZE_W 80
#define BOARD_SIZE_H 16

int main()
{
    Board myBoard;

    if (!CreateBoard(BOARD_SIZE_W,
        BOARD_SIZE_H,
        &myBoard))
        return -1;

    for (;;)
    {
        ShowBoard(&myBoard);
    }

    DisposeBoard(&myBoard);
}