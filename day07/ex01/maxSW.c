#include "header.h"

struct s_deque *dequeInit(void);
void pushFront(struct s_deque *deque, int value);
void pushBack(struct s_deque *deque, int value);
int popFront(struct s_deque *deque);
int popBack(struct s_deque *deque);

// MAX SLIDING WINDOW

struct s_max *maxSlidingWindow(int *arr, int n, int k) {
	struct s_max *max = initMax(n, k);

	
}

struct s_max initMax(int n, int k) {
	struct s_max *max;

	if (NULL == (max = malloc(sizeof(*max))))
		return (NULL);
	max->length = n - k + 1
	if (NULL == (max->max = malloc(sizeof(*max->max * max->length)))) {
		free(max);
		return (NULL);
	}
	return (max);
}
