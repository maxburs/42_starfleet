#ifndef HEADER_H
# define HEADER_H

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

void  sortArts(struct s_art **arts);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/

struct s_art **getArts(void);
int artsInOrder(struct s_art **arts);
void printArts(struct s_art **arts);


/*--------------------------------
  &  your own other function
  --------------------------------*/

void swap(struct s_art **art1, struct s_art **art2);

#endif
