#include "header.h"
#include <string.h> //memcpy()

void insertionSort(struct s_player **players)
{
	struct s_player **player;

	player = players;
	while (*player)
	{
		insert(players, player);
		player++;
	}	
}

void insert(struct s_player **array, struct s_player **player)
{
	struct s_player **new_position;

	new_position = player;
	while (new_position > array)
	{
		if ((*(new_position - 1))->score >= (*player)->score && (*player)->score >= (*new_position)->score)
		{
			insert_at(player, new_position);
			return ;
		}
		new_position--;
	}
	insert_at(player, new_position);
}

void insert_at(struct s_player **player, struct s_player **new_position)
{
	struct s_player *swap;

	swap = *player;
	memcpy(new_position + 1, new_position, sizeof(*player) * (player - new_position));
	*new_position = swap;
}
