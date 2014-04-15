#include <stdio.h>
#include <stdlib.h>
#include "Token.h"
#include "Tokenlist.h"

void initTokenlist(Tokenlist *list) {
	list->used = 0; // keep track of the size of elements
	list->size = 1; // the maximum size of elements
	list->elements = (Token *)malloc(1 * sizeof(Token)); // keep the 1 just to be clear
}

void insertTokenlist(Tokenlist *list, Token token) {
	if(list->used == list->size) {
		// double the size of Tokenlist
		// and realloc the chunck of memory pointed by elements
		list->size *= 2;
		list->elements = (Token *)realloc(list->elements, list->size * sizeof(Token));
	}
	list->elements[list->used] = token;
	list->used++;
}

void dumpTokenlist(Tokenlist *list) {
	// loop through the Tokenlist
	// and print every Token
	for(int i = 0; i < list->used; i++) {
		Token *token = &list->elements[i];
		printf("%s | %s | line %d | col %d-%d\n", token->type, token->value, token->line, token->start, token->end);
	}
}