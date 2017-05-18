#include "header.h"
#include <string.h> //NULL

void quickSort(struct s_player **players)
{
	struct s_player **pivot;

	if (NULL == *players)
		return ;
	pivot = players;
	while (*pivot)
		pivot++;
	pivot--;
	quickSortRecursive(players, pivot);
}

void quickSortRecursive(struct s_player **players, struct s_player **pivot)
{
	struct s_player **right;
	struct s_player **unsorted;

	right = players;
	unsorted = players;
	while (unsorted < pivot)
	{
		if ((*unsorted)->score > (*pivot)->score)
		{
			swap(unsorted, right);
			right++;
		}
		unsorted++;
	}
	swap(right, pivot);
	if (players < right - 1)
		quickSortRecursive(players, right - 1);
	if (right + 1 <  pivot)
		quickSortRecursive(right + 1, pivot);
}

void swap(struct s_player **player1, struct s_player **player2)
{
	struct s_player *swap;

	swap = *player1;
	*player1 = *player2;
	*player2 = swap;
}