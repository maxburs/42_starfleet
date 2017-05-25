#include "header.h"
#include <stdlib.h> //malloc(), free()
#include <string.h> //NULL

double optimizedBestPrice(int pizzaSize, double *prices) {
	int *slices;
	double bestPrice = 0;

	if (NULL == (slices = malloc(sizeof(*slices) * (pizzaSize + 1))))
		return (-1);
	recursiveStep(pizzaSize, slices, 0, &bestPrice, prices, pizzaSize);
	free(slices);
	return (bestPrice);
}

void recursiveStep(int sizeLeft, int *slices, int step, double *bestPrice, double *prices, int maxSize) {
	slices[step] = 0;
	if (sizeLeft == 0)
		comparePrices(slices, bestPrice, prices);
	while (0 < maxSize--) {
		slices[step] = maxSize;
		recursiveStep(sizeLeft - maxSize, slices, step + 1, bestPrice, prices,
			sizeLeft < maxSize + 1 ? sizeLeft : maxSize);
	}
}

void comparePrices(int *slices, double *bestPrice, double *prices) {
	double price = 0;

	while (*slices) {
		price += prices[*slices];
		slices++;
	}
	if (*bestPrice < price)
		*bestPrice = price;
}
