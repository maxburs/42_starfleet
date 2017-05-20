#ifndef HEADER_H
# define HEADER_H

#include <stdbool.h>

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
void	saveTheSequoia(struct s_node **root);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *genMinHeap(unsigned seed); //generate a min heap
void printBinaryTree(struct s_node * t); //print a binary tree


/*--------------------------------
  &  your own other function
  --------------------------------*/

_Bool bubbleSwitch(struct s_node **root);
void rotate_left(struct s_node **root, struct s_node *left);
void rotate_right(struct s_node **root, struct s_node *right);
void swap(struct s_node **node1, struct s_node **node2);

#endif
