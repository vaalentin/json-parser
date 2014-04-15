#include "Tokenlist.h"

#ifndef H_LEXER
#define H_LEXER

void processToken(Tokenlist *list, char type[], char value[], int line, int start, int end);

Tokenlist lex(char path[]);

#endif