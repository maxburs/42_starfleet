#include "header.h"
#include <stdbool.h>
#include <stdlib.h>

char *precious(int *text, int size)
{
	struct s_node *list;
	char *str;
	int	i;

	if (NULL == (list = build_list(CS)))
		return (NULL);
	if (NULL == (str = malloc(size + 1)))
	{
		free_list(list);
		return (NULL);
	}
	i = 0;
	while (i < size)
	{
		list = move(list, *text);
		str[i] = list->c;
		text++;
		i++;
	}
	free_list(list);
	return (str);
}

struct s_node *move(struct s_node *list, int move)
{
	if (move > 0)
	{
		while (move--)
			list = list->next;
	}
	else if (move < 0)
	{
		while (move++)
			list = list->prev;
	}
	return (list);
}

struct s_node *build_list(char *cs)
{
	struct s_node *list;
	struct s_node *new_node;

	list = NULL;
	while (*cs)
	{
		if (NULL == (new_node = malloc(sizeof(*new_node))))
		{
			free_list(list);
			return (NULL);
		}
		new_node->c = *cs;
		push_node(&list, new_node);
		cs++;
	}
	return (list);
}

void push_node(struct s_node **list, struct s_node *node)
{
	if (*list == NULL)
	{
		node->next = node;
		node->prev = node;
		*list = node;
	}
	else
	{
		node->next = (*list);
		node->prev = (*list)->prev;
		(*list)->prev->next = node;
		(*list)->prev = node;
	}
}

void free_list(struct s_node *node)
{
	struct s_node *node2;
	struct s_node *start;

	if (node == NULL)
		return ;
	start = node;
	while (true)
	{
		node2 = node->next;
		free(node);
		if (node2 == start)
			break ;
		node = node2->next;
		free(node2);
		if (node == start)
			break ;
	}
}