#include "header.h"
#include <string.h> //bzero()
#include <stdint.h> //uint64_t
#include <limits.h> //INT_MAX
#include <stdlib.h> //malloc(), free()

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
	
	if (NULL == (solutions = malloc(sizeof(**solutions) * n * ((unsigned int)INT_MAX + 1))))
	bzero(solutions, sizeof(**solutions) * n * ((unsigned int)INT_MAX + 1));
	solution = findProbability(position / 8, position % 8, n, solutions);
	free(solutions);
	return (solution);
}

//i : y, j : x

double findProbability(char x, char y, int moves, double **solutions) {
	double solution;

	if (moves == 0)
		return (0);
	solution = solutions[y * 8 + x][moves - 1];
	if (solution)
		return (solution);
	for (char i = -2; i <= 2; i++) {
		if (i == 0)
			continue ;
		for (char j = -2; j <= 2; j++) {
			if (j == 0)
				continue ;
			if (x + j < 0 || x + j > 7 || y + i < 0 || y + i > 0)
				solution += 0.125;
			else
				solution += findProbability(x + j, y + i, moves - 1, solutions) / 8;
		}
	}
	solutions[y * 8 + x][moves - 1] = solution;
	return (solution);
}
