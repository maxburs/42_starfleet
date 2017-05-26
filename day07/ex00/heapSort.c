#include "header.h"
#include <stdbool.h> //bool, true, false
#include <string.h> //strcmp()

void heapSort(struct s_art **masterpiece, int n) {
	heapify(masterpiece, n, 0);
	while (n > 0) {
		swap(masterpiece, masterpiece + n - 1);
		siftDown(masterpiece, n, 0);
		n--;
	}
}

void heapify(struct s_art **masterpiece, int n, int element) {
	if (element >= n)
		return ;
	heapify(masterpiece, n, 2 * element + 1);
	heapify(masterpiece, n, 2 * element + 2);
	siftDown(masterpiece, n, element);
}

void siftDown(struct s_art **masterpiece, int n, int element) {
	int left = 2 * element + 1;
	int right = 2 * element + 2;

	bool smallerLeft = isSmaller(masterpiece, n, element, left);
	bool smallerRight = isSmaller(masterpiece, n, element, right);

	if (smallerLeft && smallerRight) {
		if (isSmaller(masterpiece, n, left, right))
			smallerLeft = false;
		else
			smallerRight = false;
	}

	if (smallerLeft) {
		swap(masterpiece + element, masterpiece + left);
		siftDown(masterpiece, n, left);
	}
	else if (smallerRight) {
		swap(masterpiece + element, masterpiece + right);
		siftDown(masterpiece, n, right);
	}
}

bool isSmaller(struct s_art **masterpiece, int n, int art1, int art2) {
	return ((art1 >= n || art2 >= n))
		return (false);
	return (strcmp(masterpiece[art1]->name, masterpiece[art2]->name) < 0);
}

void swap(struct s_art **art1, struct s_art **art2) {
	struct s_art *swap;

	swap = *art1;
	*art1 = *art2;
	*art2 = swap;
}
