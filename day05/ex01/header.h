#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_prices
{
	double *items;
	int length;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
double bestPrice(int pizzaSize, double *prices);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

// PARSING

struct s_prices *readList();

/*--------------------------------
  &  your own other function
  --------------------------------*/
void recursiveStep(int sizeLeft, int *slices, int step, double *bestPrice, double *prices);
void comparePrices(int *slices, double *bestPrice, double *prices);

#endif
