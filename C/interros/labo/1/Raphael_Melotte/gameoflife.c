#include <stdio.h>
#include "gameoflife.h"

// to get random numbers:
#include <stdlib.h>
#include <time.h>

struct Board init(unsigned w, unsigned h)
{
    if (w < 0 || h < 0)
    {
        fprintf(stderr, "w OR h OUT OF RANGE\n");
        exit(1);
    }
    struct Board board;
    board.w = w;
    board.h = h;

    bool ** grid = malloc(h * sizeof(bool *));
    for (unsigned i = 0; i < h; ++i)
        grid[i] = malloc(w * sizeof(bool));

    // initializing the board:
    for (unsigned i = 0; i < board.h; ++i)
    {
        for (unsigned j = 0; j < board.w; ++j)
        {
            grid[i][j] = false;
        }
    }

    board.grid = grid;
    return board;
}

void fill(struct Board * board, double p)
{
    if (p < 0 || p > 1)
    {
        fprintf(stderr, "P OUT OF RANGE\n");
        exit(1);
    }
    // we need to seed once:
    srand(time(NULL));

    for (unsigned i = 0; i < board -> h; ++i)
    {
        for (unsigned j = 0; j < board -> w; ++j)
        {
            // we need a random number between 0 and 1:
            double random = (double)rand() / (double) RAND_MAX;
            if (random <= p)
                board -> grid[i][j] = true;
            else
                board -> grid[i][j] = false;
        }
    }
}

void clear(struct Board ** board)
{
    for (unsigned i = 0; i < (*board) -> h; ++i)
        free((*board) -> grid[i]);
    free((*board) -> grid);
    *board = NULL;
}

void print(const struct Board * board)
{
    for (unsigned i = 0; i < board -> w; ++i)
    {
        for (unsigned j = 0; j < board -> h; ++j)
        {
            printf("%d", board -> grid[j][i]);
            printf(" ");
        }
        printf("\n");
    }
}

unsigned countNeighbours(const struct Board * board, unsigned i,
                         unsigned j)
{
    // we may use negative values here:
    long int k = (long int) i;
    long int l = (long int) j;
    long int count;
    if (board -> grid[i][j] == true)
        count = -1;
    else
        count = 0;
    for (long int a = k - 1; a <= k + 1 ; ++a)
    {
        for (long int b = l - 1; b <= l + 1; ++b)
        {
            if (isInBoard(board, a, b) && board -> grid[a][b])
            {
                count++;
            }

        }
    }
    // we counted the cell itself as a neighbours, so we have to decrease once:

    return count;
}

bool isInBoard(const struct Board * board, long int i, long int j)
{
    return (i >= 0 && i < (long int) board -> h && j >= 0 &&
            j < (long int) board -> w);
}

void nextGeneration(struct Board * board)
{
    // a temp grid that will hold the next state of the board:
    bool nextBoard[board -> h][board -> w];

    for (unsigned i = 0; i < board -> h; ++i)
    {
        for (unsigned j = 0; j < board -> w; ++j)
        {
            int n = countNeighbours(board, i , j);
            if (n == 2)
            {
                nextBoard[i][j] = board -> grid[i][j];
            }
            else if (n == 3)
            {
                nextBoard[i][j] = true;
            }
            else
            {
                nextBoard[i][j] = false;
            }
        }
    }
    // we have the next state of the board, we can change the grid itself:
    for (unsigned i = 0; i < board -> h; ++i)
    {
        for (unsigned j = 0; j < board -> w; ++j)
        {
            board -> grid[i][j] = nextBoard[i][j];
        }
    }
}
