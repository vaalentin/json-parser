#include "Token.h"

#ifndef H_TOKENLIST
#define H_TOKENLIST

typedef struct Tokenlist {
	Token *array;
	size_t size;
	size_t used;
} Tokenlist;

void initTokenlist(Tokenlist *list, size_t size);

void appendTokenlist(Tokenlist *list, Token token);

void emptyTokenlist(Tokenlist *list);

void clearTokenlist(Tokenlist *list);

void printTokenlist(Tokenlist *list);

int getTokenlistSize(Tokenlist *list);

#endif