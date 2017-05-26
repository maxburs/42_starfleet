#ifndef HEADER_H
# define HEADER_H

#include <stdbool.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_art {
	char *name;
	int price;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void heapSort(struct s_art **masterpiece, int n);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_art **getArts(void);

/*--------------------------------
  &  your own other function
  --------------------------------*/
void heapify(struct s_art **masterpiece, int n, int element);
void siftDown(struct s_art **masterpiece, int n, int element);
bool isSmaller(struct s_art **masterpiece, int n, int art1, int art2);
void swap(struct s_art **art1, struct s_art **art2);

#endif
