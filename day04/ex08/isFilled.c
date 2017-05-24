#include "header.h"

int isFilled(unsigned int parkingRow)
{
	if (parkingRow > 1)
	{
		if ((1 & parkingRow) ^ 1)
			return (0);
	}
	if (parkingRow)
		return (isFilled(parkingRow >> 1));
	return (1);
}
