#include <stdio.h>
#include "gameoflife.h"

void testCreatePrintNewBoard(int h, int w)
{
    printf("TestPrintNewBoard: \n");
    struct Board board = init(h, w);
    print(&board);
    struct Board * p = &board;
    clear(&p);
    printf("\n");
}

void testFill()
{
    printf("TestFill: \n");
    double prob = 0.5;
    struct Board board = init(10, 5);
    fill(&board, prob);
    printf("prob is: %f\n", prob);
    print(&board);
    struct Board * p = &board;
    clear(&p);
    printf("\n");
}

void testCountNeighbours()
{
    printf("TestCountNeighbours: \n");
    int h = 10, w = 5, i = 0, j = 0;
    struct Board board = init(h, w);
    fill(&board, 0.4);
    print(&board);
    printf("Neighbours of %d,%d : %d \n", i, j , countNeighbours(&board,
            i, j));


    struct Board * p = &board;
    clear(&p);
    printf("\n");
}

void testNextGeneration()
{
    printf("TestNextGeneration: \n");
    int h = 10, w = 5, maxGen = 10;
    struct Board board = init(h, w);
    fill(&board, 0.5);
    printf("initial board: \n");
    print(&board);

    for (int gen = 0; gen < maxGen; ++gen)
    {
        nextGeneration(&board);
        printf("board at generation %d: \n", gen);
        print(&board);
    }

    struct Board * p = &board;
    clear(&p);
    printf("\n");
}

void testAll()
{
    testCreatePrintNewBoard(10, 5);
    testFill();
    testCountNeighbours();
    testNextGeneration();
}
int main()
{
    testAll();

    int h = 10, w = 15, maxGen = 5;
    struct Board board = init(h, w);

    for (unsigned i = 0; i < board.h; ++i)
    {
        for (unsigned j = 0; j < board.w; ++j)
        {
            if (i <= 5 && j <= 5)
                board.grid[i][j] = true;
            else
                board.grid[i][j] = false;
        }

    }

    printf("initial board: \n");
    print(&board);

    for (int gen = 0; gen < maxGen; ++gen)
    {
        nextGeneration(&board);
        printf("board at generation %d: \n", gen);
        print(&board);
    }

    struct Board * p = &board;
    clear(&p);
    printf("\n");

    return 0;
}
