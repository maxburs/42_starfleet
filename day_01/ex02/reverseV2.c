#include "header.h"
#include <string.h> //NULL
#include <stdio.h> //fputc(), fputs()
#include <stdlib.h> //malloc(), free()
#include <stdbool.h> //true

/*
** for my purposes pop and push will operate on the front of the stack
*/

struct s_stack *stackInit(void)
{
	struct s_stack *stack;

	if (NULL == (stack = malloc(sizeof(*stack))))
		return (NULL);
	bzero(stack, sizeof(*stack));
	return (stack);
}

void *pop(struct s_stack *stack)
{
	struct s_item *item;
	void *word;

	item = stack->item;
	if (item == NULL)
		return (NULL);
	word = item->word;
	stack->item = item->next;
	free(item);
	return (word);
}

void push(struct s_stack *stack, char *word)
{
	struct s_item *new_item;

	new_item = create_new_item(word);
	if (new_item == NULL)
		return ;
	new_item->next = stack->item;
	stack->item = new_item;
}

struct s_item *create_new_item(char *word)
{
	struct s_item *item;

	if (NULL == (item = malloc(sizeof(*item))))
		return (NULL);
	item->next = NULL;
	item->word = word;
	return (item);
}

void printReverseV2(struct s_node *lst)
{
	struct s_stack *stack;
	char *word;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	if ((word = pop(stack)))
	{
		while (true)
		{
			fputs(word, stdout);
			if (NULL == (word = pop(stack)))
				break ;
			fputc(' ', stdout);
		}
	}
	fputc('\n', stdout);
}
