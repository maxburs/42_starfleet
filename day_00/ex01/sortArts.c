#include "header.h"
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

//selection sort

void  sortArts(struct s_art **arts)
{
	struct s_art **start;
	struct s_art **smallest;

	start = arts;
	while (*start)
	{
		arts = start + 1;
		smallest = start;
		while (*arts)
		{
			if (strcmp((*smallest)->name, (*arts)->name) > 0)
				smallest = arts;
			arts++;
		}
		swap(start, smallest);
		start++;
	}
}

void swap(struct s_art **art1, struct s_art **art2)
{
	struct s_art *swap;

	swap = *art1;
	*art1 = *art2;
	*art2 = swap;
}
