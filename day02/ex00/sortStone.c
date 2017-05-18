#include "header.h"
#include <stdbool.h>

void sortStones(struct s_stone **stone)
{
	struct s_stone **last;
	struct s_stone **current;
	struct s_stone **next;
	_Bool change_made;

	change_made = true;
	while (change_made)
	{
		change_made = false;
		last = stone;
		current = find_next_group(last);
		while (*current)
		{
			next = find_next_group(current);
			if ((*current)->size < (*last)->size)
			{
				swap(last, current, next); //after this is performed current & next variables will be swapped
				change_made = true;
			}
			else
				last = current;
			current = next;
		}
	}
}

struct s_stone **find_next_group(struct s_stone **stone)
{
	int size = (*stone)->size;

	while (*stone && size == (*stone)->size)
	{
		stone = &(*stone)->next;
	}
	return (stone);
}

void swap(struct s_stone **last, struct s_stone **current, struct s_stone **next)
{
	struct s_stone *swap;

	swap = *last;
	*last = *current;
	*current = *next;
	*next = swap;
}
