#include "header.h"
#include <stdlib.h> //malloc(), free()
#include <string.h> //bzero()

double	probaNephewWillLive(int nStairs, int nPunch, int nephewStair) {
	double **odds = NULL;
	double result;

	if (nephewStair > nStairs)
		return (-1);
	odds = mallocArray(nStairs - nephewStair, nPunch);
	result = findOdds(nStairs, nPunch, nephewStair, odds);
	freeArray(odds, nStairs - nephewStair);
	return (result);
}

double findOdds(int nStairs, int nPunch, int nephewStair, double **odds) {
	double result = 0;

	(void)(odds);
	if (nephewStair > nStairs)
		return (0);
	if (nPunch < 1)
		return (1);
	if (odds[nStairs - nephewStair - 1][nPunch - 1])
		return (odds[nStairs - nephewStair - 1][nPunch - 1]);
	for (int i = nephewStair + 1; i < nStairs; i++) {
		result += findOdds(i, nPunch - 1, nephewStair, odds) / nStairs;
	}
	odds[nStairs - nephewStair - 1][nPunch - 1] = result;
	return (result);
}

double **mallocArray(int stairsLeft, int nPunch) {
	double **odds;

	if (NULL == (odds = malloc(sizeof(*odds) * stairsLeft)))
		return (NULL);
	bzero(odds, sizeof(*odds) * stairsLeft);
	for (int i = 0; i < stairsLeft; i++) {
		odds[i] = malloc(sizeof(**odds) * nPunch);
		if (NULL == odds[i]) {
			freeArray(odds, stairsLeft);
			return (NULL);
		}
		bzero(odds[i], sizeof(**odds) * nPunch);
	}
	return (odds);
}

void freeArray(double **array, int stairsLeft) {
	while (stairsLeft--)
		free(array[stairsLeft]);
	free(array);
}
