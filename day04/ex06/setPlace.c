#include "header.h"

unsigned int setPlace(unsigned int parkingRow, int pos)
{
	return ((1 << pos) | parkingRow);
}