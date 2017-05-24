#include "header.h"

#include <stdio.h>

int occupiedPlaces(unsigned int parkingRow)
{
	int result = 0;

	if (parkingRow & 0x80000000)
	{
		parkingRow &= 0x7FFFFFFF;
		result = add(result, 1);
	}
	while (parkingRow)
	{
		if (parkingRow)
			result = add(result, 1);
		parkingRow = parkingRow & (parkingRow - 1);
	}
	return (result);
}

int add(int num, int bit)
{
	if (num & bit)
	{
		return (add(num & ~bit, bit << 1));
	}
	return (num | bit);
}
