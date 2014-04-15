#include "Token.h"

#ifndef H_TOKENLIST
#define H_TOKENLIST

typedef struct Tokenlist {
	Token *elements;
	int used, size;
} Tokenlist;

void initTokenlist(Tokenlist *list);

void insertTokenlist(Tokenlist *list, Token token);

void dumpTokenlist(Tokenlist *list);

#endif