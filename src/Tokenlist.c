#include <stdio.h>
#include <stdlib.h>
#include "Tokenlist.h"
#include "Token.h"

void initTokenlist(Tokenlist *list, size_t size) {
	list->array = (Token *)malloc(size * sizeof(Token));
	list->size = size;
	list->used = 0;
}

void appendTokenlist(Tokenlist *list, Token token) {
	if(list->used == list->size) {
		list->size *= 2;

		int size = list->size * sizeof(Token);
		printf("----- AUGMENT TOKEN LIST SIZE to %d -----\n", size);

		list->array = (Token *)realloc(list->array, size);
	}
	list->array[list->used++] = token;
}

void emptyTokenlist(Tokenlist *list) {
	list->array = (Token *)realloc(list->array, 1 * sizeof(Token));
	list->used = 0;
	list->size = 0;
}

void clearTokenlist(Tokenlist *list) {
	free(list->array);
	list->array = NULL;
	list->used = 0;
	list->size = 0;
}

void printTokenlist(Tokenlist *list) {
	for(int i = 0; i < 2; i++) {
		printf("%s\n", list->array[i].type);
	}
}

int getTokenlistSize(Tokenlist *list) {
	int size = list->used;
	return size;
}