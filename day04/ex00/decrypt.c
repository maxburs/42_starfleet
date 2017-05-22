#include "header.h"
#include <stdio.h> //sprintf()
#include <string.h> //strdup()

#define BUFF_SIZE 16

char *getSum(char *a, char *b)
{
	char sum[BUFF_SIZE];

	sprintf(sum, "%d", toInt(a) + toInt(b));
	return (strdup(sum));
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