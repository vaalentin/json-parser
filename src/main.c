/**
 * \file main.c
 * \version 0.0.1
 */
#include <stdio.h>
#include <stdlib.h>
#include "lexer.h"

typedef struct Token {
	
	char *type;
	int line, column;

} Token;

typedef struct Tokenlist {
	
	Token *elements;
	int used, size;

} Tokenlist;

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

int main(int argc, char *argv[]) {

	Tokenlist tokens;
	initTokenlist(&tokens);

	for(int i = 0; i < 10; i++) {
		Token token;
		token.line = i;
		token.type = "hello world";
		insertTokenlist(&tokens, token);
	}

	dumpTokenlist(&tokens);

	return 0;
}