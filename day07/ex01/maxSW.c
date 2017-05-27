#include "header.h"
#include <string.h> //NULL
#include <stdlib.h> //malloc(), free()

#include <stdio.h>
void printDeque(struct s_deque *deque) {
	struct s_dequeNode *node;

	node = deque->first;
	if (node)
		printf("deque: %d", node->value);
	else
		printf("deque: (emtpy)");
	node = node->next;
	while (node) {
		printf(", %d", node->value);
		node = node->next;
	}
	printf("\n");
}

struct s_deque *dequeInit(void) {
	struct s_deque *deque;

	if (NULL == (deque = malloc(sizeof(*deque))))
		return (NULL);
	deque->first = NULL;
	deque->last = NULL;
	return (deque);
}

void pushFront(struct s_deque *deque, int value) {
	struct s_dequeNode *node;

	if (NULL == (node = createDequeNode(value)))
		return ;
	node->next = deque->first;
	deque->first = node;
	if (NULL == deque->last)
		deque->last = node;
	else
		node->next->prev = node;
}

void pushBack(struct s_deque *deque, int value) {
	struct s_dequeNode *node;

	if (NULL == (node = createDequeNode(value)))
		return ;
	node->prev = deque->last;
	deque->last = node;
	if (NULL == deque->first)
		deque->first = node;
	else
		node->next->prev = node;
}

int popFront(struct s_deque *deque) {
	struct s_dequeNode *node;
	int value;

	node = deque->first;
	deque->first = node->next;
	if (node->next == NULL)
		deque->last = NULL;
	else
		node->next->prev = NULL;
	value = node->value;
	free(node);
	return (value);
}

int popBack(struct s_deque *deque) {
	struct s_dequeNode *node;
	int value;

	node = deque->last;
	deque->last = node->prev;
	if (node->prev == NULL)
		deque->first = NULL;
	else
		node->prev->next = NULL;
	value = node->value;
	free(node);
	return (value);
}

// MAX SLIDING WINDOW

struct s_max *maxSlidingWindow(int *arr, int n, int k) {
	struct s_max *max = initMax(n, k);
	struct s_deque *deque;
	int maxValue;

	if (max->length == 1) {
		max->max[0] = arrayMaxValue(arr, n);
		return (max);
	}
	deque = dequeInit();
	for (int i = 0; i < k; i++) {
		pushFront(deque, arr[i]);
	}
	maxValue = dequeMaxValue(deque);
	max->max[0] = maxValue;
	printDeque(deque);
	printDeque(deque);
	for (int i = k; i < n; i++) {
		if (popBack(deque) == maxValue) {
			pushFront(deque, arr[i]);
			maxValue = dequeMaxValue(deque);
		}
		else {
			pushFront(deque, arr[i]);
			if (arr[i] > maxValue)
				maxValue = arr[i];
		}
		max->max[i - k + 1] = maxValue;
		printDeque(deque);
	}
	while (deque->first)
		popFront(deque);
	//free(deque); wtf
	return (max);
}

struct s_max *initMax(int n, int k) {
	struct s_max *max;

	if (NULL == (max = malloc(sizeof(*max))))
		return (NULL);
	max->length = n - k + 1;
	if (max->length < 1)
		max->length = 1;
	if (NULL == (max->max = malloc(sizeof(*max->max * max->length)))) {
		free(max);
		return (NULL);
	}
	return (max);
}

struct s_dequeNode *createDequeNode(int value) {
	struct s_dequeNode *node;

	if (NULL == (node = malloc(sizeof(*node))))
		return (NULL);
	node->next = NULL;
	node->prev = NULL;
	node->value = value;
	return (node);
}

int dequeMaxValue(struct s_deque *deque) {
	struct s_dequeNode *node;
	int maxValue;

	node = deque->first;
	if (node == NULL)
		return (0);
	maxValue = node->value;
	node = node->next;
	while (node) {
		if (node->value > maxValue)
			maxValue = maxValue;
		node = node->next;
	}
	return (maxValue);
}

int arrayMaxValue(int *arr, int n) {
	int maxValue = arr[0];

	while (1 < n--) {
		if (maxValue < arr[n])
			maxValue = arr[n];
	}
	return (maxValue);
}
