#include "header.h"
#include <stdlib.h> //malloc(), free()
#include <string.h> //NULL
#include <stdio.h>

double optimizedBestPrice(int pizzaSize, double *prices) {
	return (bestPricePair(pizzaSize, prices));
}

double bestPricePair(int pizzaSize, double *prices)
{
	double price = 0;
	double pricePossibility;

	if (pizzaSize > 0)
		prices[pizzaSize - 1] = bestPricePair(pizzaSize - 1, prices);
	for (int i = 0; i <= pizzaSize; i++, pizzaSize--) {
		pricePossibility = prices[i] + prices[pizzaSize];
		if (price < pricePossibility)
			price = pricePossibility;
	}
	return (price);
}
