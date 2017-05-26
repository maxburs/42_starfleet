#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame) {
	double winChance = 1;
	double greenChance = 0;

	while (firstDollarsBet < dollarsWanted) {
		if (nbGame < 1)
			return (greenChance);
		greenChance += probabilityWin(firstDollarsBet / 2, dollarsWanted, nbGame - 1)  * winChance / 37;
		winChance = winChance * 18 / 37;
		firstDollarsBet *= 2;
		nbGame--;
	}
	return (winChance + greenChance);
}
