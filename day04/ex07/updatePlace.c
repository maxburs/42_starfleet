#include "header.h"
#include <limits.h>

unsigned int updatePlace(unsigned int parkingRow, int pos, int value)
{
	parkingRow &= ~(1 << pos);
	return (parkingRow | (value << pos));
}
