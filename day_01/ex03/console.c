#include "header.h"
#include <stdio.h> //fputs(), fputc(), scanf()
#include <stdbool.h> //true
#include <string.h> //strlen(), NULL, strdup(), strncpy()
#include <stdlib.h> //malloc(), free()
#include <strings.h> //bzero()

char *console(void)
{
	struct s_stack *stack;
	char message[MAX_MESSAGE_LENGTH + 1];
	char buff[MAX_MESSAGE_LENGTH + 1];
	int idx;

	stack = initStack();
	message[0] = '\0';
	while (true)
	{
		fputs("\e[5;96mThanks for choosing Space Cheap!\e[0m ", stdout);
		if (EOF == scanf("%[^\n]%*c", buff))
			break ;
		if (strcmp(buff, "SEND") == 0)
			break ;
		else if (strcmp(buff, "UNDO") == 0)
		{
			idx = pop(stack);
			message[idx] = '\0';
		}
		else
		{
			idx = strlen(message);
			strncpy(&message[idx], buff, sizeof(message) - idx);
			push(stack, idx);
		}
		fputs(message, stdout);
		fputc('\n', stdout);
	}
	return (strdup(message));
}

struct s_stack *initStack(void)
{
	struct s_stack *stack;

	if (NULL == (stack = malloc(sizeof(*stack))))
		return (NULL);
	bzero(stack, sizeof(*stack));
	return (stack);
}

int pop(struct s_stack *stack)
{
	struct s_item *item;
	int idx;

	item = stack->item;
	if (item == NULL)
		return (0);
	idx = item->idx;
	stack->item = item->next;
	free(item);
	return (idx);
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *new_item;

	new_item = create_new_item(idx);
	if (new_item == NULL)
		return ;
	new_item->next = stack->item;
	stack->item = new_item;
}

struct s_item *create_new_item(int idx)
{
	struct s_item *item;

	if (NULL == (item = malloc(sizeof(*item))))
		return (NULL);
	item->next = NULL;
	item->idx = idx;
	return (item);
}
