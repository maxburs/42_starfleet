#include "header.h"
#include <stdbool.h> //bool, true, false
#include <string.h> //NULL

#include <stdio.h>

void saveTheSequoia(struct s_node **root)
{
	if (root == NULL)
		return ;
	while (bubbleSwitch(root)) {};
}

_Bool bubbleSwitch(struct s_node **root)
{
	_Bool change = false;

	if (*root == NULL)
		return (false);
	if ((*root)->left && ((*root)->left->value > (*root)->value))
	{
		rotate_left(root, (*root)->left);
		change = true;
	}
	if ((*root)->right && ((*root)->right->value > (*root)->value))
	{
		rotate_right(root, (*root)->right);
		change = true;
	}
	change = bubbleSwitch(&(*root)->left) || change;
	change = bubbleSwitch(&(*root)->right) || change;
	return (change);
}


void rotate_left(struct s_node **root, struct s_node *bottom)
{
	struct s_node *top;

	top = *root;
	swap (&top->right, &bottom->right);
	top->left = bottom->left;
	bottom->left = top;
	*root = bottom;
}


void rotate_right(struct s_node **root, struct s_node *bottom)
{
	struct s_node *top;

	top = *root;
	swap (&top->left, &bottom->left);
	top->right = bottom->right;
	bottom->right = top;
	*root = bottom;
}

void swap(struct s_node **node1, struct s_node **node2)
{
	struct s_node *swap;

	swap = *node1;
	*node1 = *node2;
	*node2 = swap;
}

