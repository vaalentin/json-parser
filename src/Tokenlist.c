#include <stdio.h>
#include <stdlib.h>
#include "Tokenlist.h"
#include "Token.h"

void initTokenlist(Tokenlist *list, size_t size) {
	list->array = (int *)malloc(size * sizeof(Token));
	list->size = size;
	list->used = 0;
}

void appendTokenlist(Tokenlist *list, int element) {
	if(list->used == list->size) {
		list->size *= 2;
		list->array = (int *)realloc(list->array, list->size * sizeof(int));
	}
	list->array[list->used++] = element;
}

void emptyTokenlist(Tokenlist *list) {
	list->array = (int *)realloc(list->array, 1 * sizeof(int));
	list->used = 0;
	list->size = 0;
}

void clearTokenlist(Tokenlist *list) {
	free(list->array);
	list->array = NULL;
	list->used = 0;
	list->size = 0;
}

void printTokenlist(Tokenlist *array) {
	for(int i = 0; i < array->used; i++) {
		printf("%d\n", array->array[i]);
	}
}