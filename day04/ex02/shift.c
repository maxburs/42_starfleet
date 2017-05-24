#include "header.h"
#include <string.h> //strlen(), memcopy(), memset()

#include <stdio.h>

char *rightShift(char *bin, int k)
{
	int length;
	char left_fill;

	length = strlen(bin);
	left_fill = bin[0];
	if (k >= length)
		memset(bin, left_fill, length);
	else if (k > 0)
	{
		memmove(bin + k, bin, length - k);
		memset(bin, left_fill, k);
	}
	return (bin);
}

char *leftShift(char *bin, int k)
{
	int length;

	length = strlen(bin);
	if (k >= length)
		memset(bin, '0', length);
	else if (k > 0)
	{
		memmove(bin, bin + k, length - k);
		memset(bin + length - k, '0', k);
	}
	return (bin);
}

int toInt(char *bits)
{
	int num = 0;
	int negative;

	negative = *bits == '1';
	bits++;
	while (*bits)
	{
		num = ((*bits) - '0') | (num << 1);
		bits++;
	}
	if (negative)
		num = num - 32;
	return (num);
}
