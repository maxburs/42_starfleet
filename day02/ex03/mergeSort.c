#include "header.h"
#include <string.h> //size_t, memcpy()
#include <stdbool.h> //true

struct s_player **mergeSort(struct s_player **players)
{
	size_t group_size = 1;
	size_t length;
	struct s_player **group;
	struct s_player **terminator;

	terminator = find_terminator(players);
	length = terminator - players;
	while (group_size < length)
	{
		group = players;
		while (group + group_size < terminator)
		{
			merge(group, terminator, group_size);
			group += group_size * 2;
		}
		group_size *= 2;
	}
	return (players);
}

struct s_player **find_terminator(struct s_player **players)
{
	while (*players)
		players++;
	return (players);
}

void merge(struct s_player **group, struct s_player **terminator, size_t group_size)
{
	size_t new_size = new_group_size(group, terminator, group_size);
	struct s_player *new_group[new_size];
	struct s_player **group1;
	struct s_player **group2;
	size_t i;

	if (group + (group_size * 2) < terminator)
		terminator = group + (group_size * 2);
	group1 = group;
	group2 = group + group_size;
	i = 0;
	while (true)
	{
		if ((*group1)->score >= (*group2)->score)
		{
			new_group[i] = *group1;
			group1++;
			i++;
			if ((size_t)(group1 - group) == group_size)
				break ;
		}
		else
		{
			new_group[i] = *group2;
			group2++;
			i++;
			if (group2 == terminator)
				break ;
		}
	}
	while ((size_t)(group1 - group) != group_size)
	{
		new_group[i] = *group1;
		group1++;
		i++;
	}
	while (group2 != terminator)
	{
		new_group[i] = *group2;
		group2++;
		i++;
	}
	memcpy(group, new_group, new_size * sizeof(*group));
}

size_t new_group_size(struct s_player **group, struct s_player **terminator, size_t group_size)
{
	if ((size_t)(terminator - group) < group_size * 2)
		return (terminator - group);
	else
		return (group_size * 2);
}
