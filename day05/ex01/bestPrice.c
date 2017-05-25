#include "header.h"
#include <stdlib.h> //malloc(), free()
#include <string.h> //NULL

double bestPrice(int pizzaSize, double *prices) {
	return (recursiveStep(pizzaSize, prices, pizzaSize));
}

double recursiveStep(int sizeLeft, double *prices, int sliceSize) {
	double bestPrice = 0;
	double newPrice;

	if (sizeLeft < sliceSize)
		sliceSize = sizeLeft;
	while (0 < sliceSize) {
		newPrice = recursiveStep(sizeLeft - sliceSize, prices, sliceSize) + prices[sliceSize];
		if (newPrice > bestPrice)
			bestPrice = newPrice;
		sliceSize--;
	}
	return (bestPrice);
}
