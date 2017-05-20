#ifndef HEADER_H
# define HEADER_H

#include <stdbool.h> //bool

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	char	*name;
	struct s_node **children;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *getTreeOfLife(void);
void test(struct s_node *root, char *firstSpecies, char *secondSpecies);


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_status {
	struct s_node *ancestor;
	bool firstSpecies;
	bool secondSpecies;
};

struct s_status findParentRecursive(struct s_node *node, char *firstSpecies, char *secondSpecies);

#endif
  