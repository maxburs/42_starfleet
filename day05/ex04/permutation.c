#include "header.h"
#include <stdio.h> //puts()
#include <string.h> //memmove()

void printPermutations(char *str) {
	recurseMe(str, str);
}

void recurseMe(char *front, char *str) {
	char *c = str;
	char swap;

	if (*str == '\0') {
		puts(front);
		return ;
	}
	while (*c) {
		swap = *str;
		*str = *c;
		*c = swap;
		c++;
		recurseMe(front, str + 1);
	}
	swap = *str;
	memmove(str, str + 1, (c - 1) - str);
	*(c - 1) = swap;
}
