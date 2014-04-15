#include "Tokenlist.h"

#ifndef H_LEXER
#define H_LEXER

void processToken(Tokenlist *list, char type[], char value[]);

void lex(char path[]);

#endif