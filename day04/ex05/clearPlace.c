#include "header.h"

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
	return (~(1 << pos) & parkingRow);
}
