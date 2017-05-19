#include "header.h"
#include <string.h> //bzero, NULL
#include <stdlib.h> //abs
#include <stdbool.h> //true, false

struct s_info getInfo(struct s_node *root)
{
	struct s_info info;

	bzero(&info, sizeof(info));
	info.isBalanced = true;
	info.isBST = true;
	info.min = root->value ? root->value : 0;
	info.max = root->value ? root->value : 0;
	info.height = goes_through_tree(root, &info);
	return (info);
}

/*
	returns height
*/
int goes_through_tree(struct s_node *node, struct s_info *info)
{
	int left_height;
	int right_height;

	if (node == NULL)
		return (0);
	if (node->value > info->max)
		info->max = node->value;
	else if (node->value < info->min)
		info->min = node->value;
	info->elements++;
	if (node->left && (node->left->value >= node->value))
		info->isBST = false;
	else if (node->right && (node->right->value < node->value))
		info->isBST = false;
	left_height = goes_through_tree(node->left, info);
	right_height = goes_through_tree(node->right, info);
	if (abs(left_height - right_height) > 1)
		info->isBalanced = false;
	return (left_height > right_height ? left_height : right_height) + 1;
}
