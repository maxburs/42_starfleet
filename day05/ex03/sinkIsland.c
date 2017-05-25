#include "header.h"
#include <string.h> //NULL

void sinkIsland(int **map, int row, int col)
{
	if (map[row] == NULL || map[row][col] != 1)
		return ;
	map[row][col] = 0;
	sinkIsland(map, row + 1, col);
	sinkIsland(map, row, col);
	sinkIsland(map, row, col + 1);
	sinkIsland(map, row - 1, col - 1);
}
