#include "header.h"


char *precious(int *text, int size)
{
	struct s_node *list;
	char *str;

	if (NULL == (list = build_list(CS)))
		return (NULL);
	if (NULL == (str = malloc(size + 1)))
	{
		f
	}
	while (size--)
	{
		list = move(list, *text);
		putc(list->c, stdout);
	}

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
			list = list->last;
	}
	return (list);
}

struct s_node *build_list(char *cs)
{
	struct s_node *first_node;
	struct s_node *current_node;

	if (cs == NULL || *cs == '\0')
		return (NULL);
	if (NULL == (fist_node = malloc(sizeof(*first_node))))
		return (NULL);
	fist_node->c = *cs;
	cs++;
	current_node = first_node;
	while (*cs)
	{
		if (NULL == (current_node->next = malloc(sizeof(*first_node))))
		{
			free_list_fragrent(first_node);
			return (NULL);
		}
		current_node->next->last = current_node;
		current_node->next = current_node;
		current_node->c = *cs;
	}
	current_node->next = first_node;
	first_node->last = current_node;
}

void add_node(struct s_node **list, struct s_node *node)
{
	if (*list == NULL)
	{

	}
	else
	{
		node->next = (*list)->next;
		node->last = (*list);
		(*list)->next->last = node;
		(*list)->next = node;
	}
}

void free_list_fragrent(struct s_node *node)
{
	struct s_node *node2;

	while (node)
	{
		node2 = node->next;
		free(node);
		if (NULL == node2)
			break ;
		node = node2->next;
		free(node2);
	}
}