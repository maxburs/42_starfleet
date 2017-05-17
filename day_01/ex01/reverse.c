#include "header.h"
#include <string.h> //NULL
#include <stdio.h> //fputc(), fputs()

static void recursive_step(struct s_node *lst)
{
	if (lst->next)
	{
		recursive_step(lst->next);
		fputc(' ', stdout);
	}
	fputs(lst->word, stdout);
}

void printReverse(struct s_node *lst)
{
	if (lst == NULL)
		return ;
	recursive_step(lst);
	fputc('\n', stdout);
}
