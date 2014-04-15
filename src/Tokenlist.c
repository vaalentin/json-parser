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
		list->elements = (Token *)realloc(list->elements, list->size * sizeof(Token));
	}
	list->elements[list->used] = token;
	list->used++;
}

void dumpTokenlist(Tokenlist *list) {
	for(int i = 0; i < list->used; i++) {
		Token *token = &list->elements[i];
		printf("Token type %s at line %d column %d-%d\n", token->type, token->line, token->start, token->end);
	}
}