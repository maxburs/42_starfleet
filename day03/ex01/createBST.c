#include "header.h"
#include <string.h> //NULL, size_t
#include <stdlib.h> //malloc()
#include <stdbool.h> //bool, true, false

#include <stdio.h>

struct s_node *createBST(int *arr, int n)
{
	struct s_node *root;

	root = NULL;
	while (n--)
	{
		printf("inserting: %d\n", *arr);
		insertValue(&root, *arr);
		printBinaryTree(root);
		printf("\n\n");
		arr++;
	}
	return (root);
}

struct s_node *newNode(int value)
{
	struct s_node *node;

	if (NULL == (node = malloc(sizeof(*node))))
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->value = value;
	return (node);
}

/*
	returns depth
*/
size_t insertValue(struct s_node **node, int value)
{
	size_t depth;

	if (*node == NULL)
	{
		*node = newNode(value);
		return (0);
	}
	else if ((*node)->value > value)
	{
		depth = insertValue(&(*node)->left, value);
		if (shallowerThan((*node)->right, depth - 1))
		{
			rotateRight(node);
			printf("roate right at node: %d\n", (*node)->value);
			depth--;
		}
	}
	else
	{
		depth = insertValue(&(*node)->right, value);
		if (shallowerThan((*node)->left, depth - 1))
		{
			rotateLeft(node);
			printf("roate left at node: %d\n", (*node)->value);
			depth--;
		}
	}
	return (depth + 1);
}

bool shallowerThan(struct s_node *node, int depth)
{
	if (depth == -1)
		return (false);
	if (node == NULL)
		return (true);
	depth--;
	return (shallowerThan(node->right, depth) || shallowerThan(node->left, depth));
}

void rotateLeft(struct s_node **node)
{
	struct s_node *swap;

	swap = *node;
	*node = swap->right;
	swap->right = (*node)->left;
	(*node)->left = swap;
}

void rotateRight(struct s_node **node)
{
	struct s_node *swap;

	swap = *node;
	*node = swap->left;
	swap->left = (*node)->right;
	(*node)->right = swap;
}
