#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/


/*--------------------------------
  :) function you must implement
  --------------------------------*/
double	probaNephewWillLive(int nStairs, int nPunch, int nephewStair);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/


/*--------------------------------
  &  your own other function
  --------------------------------*/
double findOdds(int nStairs, int nPunch, int nephewStair, double **odds);
double **mallocArray(int stairsLeft, int nPunch);
void freeArray(double **array, int stairsLeft);

#endif
