#include "header.h"
#include <stdlib.h> //malloc(), free()
#include <string.h> //NULL

double bestPrice(int pizzaSize, double *prices) {
	int *slices;
	double bestPrice = 0;

	if (NULL == (slices = malloc(sizeof(*slices) * (pizzaSize + 1))))
		return (-1);
	recursiveStep(pizzaSize, slices, 0, &bestPrice, prices);
	free(slices);
	return (bestPrice);
}

void recursiveStep(int sizeLeft, int *slices, int step, double *bestPrice, double *prices) {
	slices[step] = 0;
	if (sizeLeft == 0)
		comparePrices(slices, bestPrice, prices);
	while (0 < sizeLeft--) {
		slices[step]++;
		recursiveStep(sizeLeft, slices, step + 1, bestPrice, prices);
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
