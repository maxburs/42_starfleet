#include "header.h"
#include <stdio.h>
#include <string.h>

#define BUFF_SIZE 16

/*
	how are we suppost to change the base withough converting it to a number???
*/

char *getSum(char *a, char *b)
{
	char sum[3];
	int i;
	int length = strlen(b);
	int val;
	int base = 1;

	i = length;
	while (i > 0)
	{
		i--;
		add(b + i, a + i);
	}
	memset(sum, '0', sizeof(sum));
	sum[2] = '\0';
	i = length - 1;
	while (i >= 0)
	{
		val = (a[i] - '0') * base;
		sum[0] += val / 10;
		sum[1] += val % 10;
		if (sum[1] > '9')
		{
			sum[1] -= 10;
			sum[0]++;
		}
		base *= 2;
		i--;
	}
	return (sum[0] == '0' ? strdup(sum + 1) : strdup(sum));
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