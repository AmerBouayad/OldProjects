#ifndef GAMEOFLIFE_H
#define GAMEOFLIFE_H
#include <stdbool.h>

struct Board
{
    // width
    unsigned w;
    // height
    unsigned h;

    // the game board. true means a full cell, false an empty cell.
    bool ** grid;
};

/*
 * Creates a new Board
 */
struct Board init (unsigned w, unsigned h);

/*
 * Free the board
 */
void clear(struct Board ** board);

/*
 * Fill the board
 */
void fill (struct Board * board, double p);

/*
 * Prints the board
 */
void print(const struct Board * board);

/*
 * Counts the neighbours of (i,j).
 */
unsigned countNeighbours(const struct Board * board, unsigned i,
                         unsigned j);

/*
 * Check if i and j are in range of the board.
 */
bool isInBoard(const struct Board * board, long int i, long int j);

/*
 * Computes the next turn and updates the board accordingly.
 */
void nextGeneration(struct Board * board);


#endif // GAMEOFLIFE_H
