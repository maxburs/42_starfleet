#include "header.h"
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#include <stdio.h>

size_t hash(char *input)
{
	size_t hash = 5381;

	printf("hash of %-12.12s: ", input);
	while (*input)
	{
		hash = ((hash << 5) + hash) + *input;
		input++;
	}
	printf("%zu\n", hash);
	return (hash);
}

struct s_dict *dictInit(int capacity)
{
	struct s_dict *dict;

	if (NULL == (dict = malloc(sizeof(*dict))))
		return (NULL);
	if (NULL == (dict->items = malloc(sizeof(*dict->items) * capacity)))
	{
		free(dict);
		return (NULL);
	}
	bzero(dict->items, sizeof(*dict->items) * capacity);
	dict->capacity = capacity;
	return (dict);
}

int	dictInsert(struct s_dict *dict, char *key, struct s_art *value)
{
	struct s_item *new_item;
	struct s_item **item;


	if (NULL == (new_item = malloc(sizeof(*item))))
		return (0);
	bzero(new_item, sizeof(*new_item));
	new_item->value = value;
	new_item->key = key;
	item = dict->items + (hash(key) % dict->capacity);
	while (*item != NULL)
		item = &(*item)->next;
	*item = new_item;
	return (1);
}

struct s_art *dictSearch(struct s_dict *dict, char *key)
{
	struct s_item *item;

	item = dict->items[hash(key) % dict->capacity];
	while (item && (strcmp(item->key, key) != 0))
		item = item->next;
	if (item)
		return (item->value);
	else
		return (NULL);
}

int searchPrice(struct s_dict *dict, char *name)
{
	struct s_art *art;

	art = dictSearch(dict, name);
	if (art)
		return (art->price);
	else
		return (-1);
}