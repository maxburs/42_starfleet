#include "header.h"

char *getXor(char *a, char *b)
{
	int i = 0;

	while (i < 6)
	{
		if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
			a[i] = '1';
		else
			a[i] = '0';
		i++;
	}
	return (a);
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
