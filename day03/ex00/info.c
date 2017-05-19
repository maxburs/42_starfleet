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
	info.depth = goes_through_tree(root, &info);
	return (info);
}

/*
	returns depth
*/
int goes_through_tree(struct s_node *node, struct s_info *info)
{
	int left_depth;
	int right_depth;

	if (node == NULL)
		return (-1);
	if (node->value > info->max)
		info->max = node->value;
	else if (node->value < info->min)
		info->min = node->value;
	info->elements++;
	if (node->left && (node->left->value >= node->value))
		info->isBST = false;
	else if (node->right && (node->right->value < node->value))
		info->isBST = false;
	left_depth = goes_through_tree(node->left, info);
	right_depth = goes_through_tree(node->right, info);
	if (abs(left_depth - right_depth) > 1)
		info->isBalanced = false;
	return (left_depth > right_depth ? left_depth : right_depth) + 1;
}
