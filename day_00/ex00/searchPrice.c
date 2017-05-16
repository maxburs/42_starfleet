#include "header.h"
#include <string.h>

int  searchPrice(struct s_art **arts, char *name)
{
	while (*arts)
	{
		if (strcmp(name, (*arts)->name) == 0)
			return ((*arts)->price);
		arts++;
	}
	return (-1);
}
