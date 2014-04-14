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
		list->array = (Token *)realloc(list->array, list->size * sizeof(int));
	}
	list->array[list->used++] = token;
}

void emptyTokenlist(Tokenlist *list) {
	list->array = (Token *)realloc(list->array, 1 * sizeof(int));
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