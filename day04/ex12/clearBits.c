#include "header.h"

unsigned int clearBits(unsigned int parkingRow, int n)
{
	if (n)
		return (parkingRow & ~((1 << n) - 1));
	else
		return (parkingRow);
}
