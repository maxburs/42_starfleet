#include "header.h"
#include <string.h> //NULL, bzero
#include <stdbool.h> //bool, true, false

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
	if (root == NULL)
		return (NULL);
	return (findParentRecursive(root, firstSpecies, secondSpecies).ancestor);
}

struct s_status findParentRecursive(struct s_node *node, char *firstSpecies, char *secondSpecies)
{
	struct s_node **children = node->children;
	struct s_status child;
	struct s_status new = {NULL, false, false};
	
	if (node == NULL)
		return (new);
	new.firstSpecies = (strcmp(node->name, firstSpecies) == 0);
	new.secondSpecies = (strcmp(node->name, secondSpecies) == 0);
	if (new.firstSpecies && new.secondSpecies)
	{
		new.ancestor = node;
		return (new);
	}
	while (*children)
	{
		child = findParentRecursive(*children, firstSpecies, secondSpecies);
		if (child.ancestor)
			return (child);
		new.firstSpecies = new.firstSpecies || child.firstSpecies;
		new.secondSpecies = new.secondSpecies || child.secondSpecies;
		if (new.firstSpecies && new.secondSpecies)
		{
			new.ancestor = node;
			return (new);
		}
		children++;
	}
	return (new);
}