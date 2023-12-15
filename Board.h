typedef struct Board
{
    int Width;
    int Height;
    unsigned char** Content;
} Board;

int CreateBoard(const int width, const int height, Board* b);

void ShowBoard(Board* b);

void DisposeBoard(Board* b);
