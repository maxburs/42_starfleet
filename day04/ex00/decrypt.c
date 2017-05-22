#include "header.h"
#include <string.h> //strlen()

char *getSum(char *a, char *b)
{
	int i;

	i = strlen(b);
	while (i > 0)
	{
		i--;
		add(b + i, a + i);
	}
	return (a);
}

void add(char *from, char *target)
{
	if (*from == '0')
		return ;
	*target = *target + 1;
	while (*target == '2')
	{
		*target = '0';
		target--;
		*target = *target + 1;
	}
}

int toInt(char *bits)
{
	int num = 0;

	while (*bits)
	{
		num = ((*bits) - '0') | (num << 1);
		bits++;
	}
	return (num);
}