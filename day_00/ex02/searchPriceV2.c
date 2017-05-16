#include "header.h"
#include <string.h>
#include <stdio.h>

int searchPrice(struct s_art **arts, int n, char *name)
{
	int split;

	n--;
	while (n > 0)
	{
		split = n / 2;
		if (strcmp(name, (*(arts + split))->name) <= 0)
		{
			n = split;
		}
		else
		{
			arts += split + 1;
			n -= split + 1;
		}
	}
	if (strcmp(name, (*arts)->name) != 0)
		return (-1);
	return ((*arts)->price);
}
