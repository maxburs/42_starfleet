#include "header.h"
#include <string.h> //strlen()

char *getAnd(char *a, char *b)
{
	int i = 0;

	if (*a == '~')
	{
		a++;
		unary(a);
	}
	if (*b == '~')
	{
		b++;
		unary(b);
	}
	while (i < 4)
	{
		if (a[i] == '1' && b[i] == '1')
			a[i] = '1';
		else
			a[i] = '0';
		i++;
	}
	return (a);
}

char *getOr(char *a, char *b)
{
	int i = 0;

	if (*a == '~')
	{
		a++;
		unary(a);
	}
	if (*b == '~')
	{
		b++;
		unary(b);
	}
	while (i < 4)
	{
		if (a[i] == '1' || b[i] == '1')
			a[i] = '1';
		else
			a[i] = '0';
		i++;
	}
	return (a);
}

void unary(char *num)
{
	while (*num)
	{
		if (*num == '0')
			*num = '1';
		else
			*num = '0';
		num++;
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