#include <stdio.h>
#include <stdlib.h>
#include "Tokenlist.h"
#include "Token.h"

void initTokenlist(Tokenlist *list) {
	list->used = 0;
	list->size = 1;
	list->elements = (Token *)malloc(1 * sizeof(Token));
}

void insertTokenlist(Tokenlist *list, Token token) {
	if(list->used == list->size) {
		list->size *= 2;
		// printf("increased size to %d elements (%lu bytes)\n", list->size, list->size * sizeof(Token));
		list->elements = (Token *)realloc(list->elements, list->size * sizeof(Token));
	}

	list->elements[list->used] = token;

	list->used++;
}

void dumpTokenlist(Tokenlist *list) {
	for(int i = 0; i < list->used; i++) {
		Token *token = &list->elements[i];
		printf("Token line: %d type: %s\n", token->line, token->type);
	}
}