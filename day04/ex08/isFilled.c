#include "header.h"

int isFilled(unsigned int parkingRow)
{
	int shift = parkingRow +  1;

	if (parkingRow & shift)
		return (0);
	else
		return (1);
}
