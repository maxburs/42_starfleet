#include "header.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc()

struct s_node *createBST(int *arr, int n) {
	struct s_node *root;

	if (n < 1)
		return (0);
	root = newNode(arr[(n / 2)]);
	root->left = createBST(arr, (n / 2));
	root->right = createBST(arr + n / 2 + 1, n - (n / 2) - 1);
	return (root);
}

struct s_node *newNode(int value) {
	struct s_node *node;

	if (NULL == (node = malloc(sizeof(*node))))
		return (NULL);
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
