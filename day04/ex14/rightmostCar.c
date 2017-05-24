#include "header.h"

int rightmostCar(unsigned int parkingRow)
{
	int carPosition = 0;

	while (parkingRow)
	{
		if (parkingRow & 1)
			return (carPosition);
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