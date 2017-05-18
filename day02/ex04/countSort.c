#include "header.h"
#include <limits.h> //UCHAR_MAX
#include <string.h> //bzero(), memcpy()

void countSort(unsigned char *utensils, int n)
{
	size_t counts[UCHAR_MAX];
	unsigned char new_array[n];

	bzero(counts, sizeof(counts));
	get_counts(counts, utensils, n);
	add_previous_counts(counts);
	sort_array(counts, utensils, new_array, n);
	memcpy(utensils, new_array, sizeof(*utensils) * n);
}

void get_counts(size_t *counts, unsigned char *utensils, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		counts[utensils[i]]++;
		i++;
	}
}

void add_previous_counts(size_t *counts)
{
	size_t total_counts;
	int i;

	total_counts = 0;
	i = 0;
	while (i < UCHAR_MAX)
	{
		total_counts += counts[i];
		counts[i] = total_counts;
		i++;
	}
}

void sort_array(size_t *counts, unsigned char *utensils, unsigned char *new_array,  int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		counts[utensils[i]]--;
		new_array[counts[utensils[i]]] = utensils[i];
		i++;
	}
}
