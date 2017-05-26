#include "header.h"
#include <string.h> //bzero()
#include <stdint.h> //uint64_t
#include <stdlib.h> //malloc(), free()

static const char g_movesX[] = {2, 2, -2, -2, 1, 1, -1, -1};
static const char g_movesY[] = {1, -1, 1, -1, 2, -2, 2, -2};
static const int g_moveCount = 8;

int getInitialPos(uint64_t board) {
	int pos = 63;

	while (0 == (board & 0x8000000000000000)) {
		board = board << 1;
		pos--;
	}
	if (board == 0x8000000000000000)
		return (pos);
	else
		return (-1);
}

double knightOut(uint64_t board, int n) {
	int position = getInitialPos(board);
	double **solutions;
	double solution;

	if (NULL == (solutions = mallocArray(n)))
		return (-1);
	solution = findProbability(position % 8, position / 8, n - 1, solutions);
	free(solutions);
	return (solution);
}

double **mallocArray(int moves) {
	double **solutions;

	if (NULL == (solutions = malloc(sizeof(*solutions) * 64)))
		return (NULL);
	bzero(solutions, sizeof(*solutions) * 64);
	for (int i = 0; i < 64; i++) {
		solutions[i] = malloc(sizeof(**solutions) * moves);
		if (NULL == solutions[i]) {
			freeArray(solutions);
			return (NULL);
		}
		bzero(solutions[i], sizeof(**solutions) * moves);
	}
	return (solutions);
}

void freeArray(double **array) {
	for (int i = 0; i < 64; i++)
		free(array[i]);
	free(array);
}

double findProbability(char x, char y, int moves, double **solutions) {
	double odds;
	char offsetX;
	char offsetY;

	if (moves < 0)
		return (0);
	odds = solutions[y * 8 + x][moves];
	if (odds)
		return (odds);
	for (unsigned char i = 0; i < g_moveCount; i++) {
		offsetX = g_movesX[i];
		offsetY = g_movesY[i];
		if (x + offsetX < 0 || x + offsetX > 7
			|| y + offsetY < 0 || y + offsetY > 7)
			odds += 0.125;
		else
			odds += findProbability(x + offsetX, y + offsetY, moves - 1, solutions) / 8;
	}
	solutions[y * 8 + x][moves] = odds;
	return (odds);
}
