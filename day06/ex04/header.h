#ifndef HEADER_H
# define HEADER_H

#include <stdint.h> //uint64_t
#include <limits.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
#define WIDTH 8

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int getInitialPos(uint64_t board);
double knightOut(uint64_t board, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void printBoard(uint64_t board);

/*--------------------------------
  &  your own other function
  --------------------------------*/
double findProbability(char x, char y, int moves, double **solutions);

#endif
