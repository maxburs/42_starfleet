#include "header.h"

int minPersons(int elements, int minPercentage) {
	int persons = 1;
	double percentage = 0;

	while (percentage < (double)minPercentage / 100) {
		percentage += (1 - percentage) * (double)persons / (double)elements;
		persons++;
	}
	return (persons);
}
