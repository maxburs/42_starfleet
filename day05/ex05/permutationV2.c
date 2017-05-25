#include "header.h"
#include <string.h> //NULL
#include <limits.h> //UCHAR_MAX, SIZE_MAX
#include <stdio.h> //puts()

void printUniquePermutations(char *str) {
	size_t letters[UCHAR_MAX + 1];

	if (str == NULL)
		return ;
	bzero(letters, sizeof(size_t) * (UCHAR_MAX + 1));
	add_letters(str, letters);
	printPermutations(str, str, letters);
}

void add_letters(char *str, size_t *letters) {
	do {
		letters[(unsigned char)*str]++;
	} while (*str++);
}

void printPermutations(char *front, char *str, size_t *letters) {
	for (unsigned char i = 0; i < UCHAR_MAX; i++) {
		if (letters[i]) {
			*str = i;
			letters[i]--;
			printPermutations(front, str + 1, letters);
			letters[i]++;
		}
	}
	if (*str == '\0')
		puts(front);
}
