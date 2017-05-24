#include "header.h"

int leftmostCar(unsigned int parkingRow)
{
	int carPosition = 0;

	if (parkingRow & 0x80000000)
		return (31);
	while (parkingRow)
	{
		if (parkingRow & 1)
		{
			if ((parkingRow >> 1)){}
			else
				return (carPosition);
		}
		carPosition = add(carPosition, 1);
		parkingRow = parkingRow >> 1;
	}
	return (-1);
}

int add(int num, int bit)
{
	if (num & bit)
	{
		return (add(num & ~bit, bit << 1));
	}
	return (num | bit);
}
