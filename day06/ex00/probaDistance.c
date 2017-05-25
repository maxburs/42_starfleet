#include "header.h"
#include <string.h> //size_t
#include <stdlib.h> //abs()

double probaDistance(int dist, int *locations, int n)
{
	size_t greater = 0;
	size_t total = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			total++;
			if (abs(locations[i] - locations[j]) > dist)
				greater++;
		}
	}
	return ((double)greater / (double)total);
}
