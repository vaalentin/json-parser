#include "Tokenlist.h"

#ifndef H_LEXER
#define H_LEXER

/**
 * Create and append a new Token to a Tokenlist
 *
 * @param list a pointer to a Tokenlist
 * @param type char array with the type of the token
 * @param value char array with the value (NULL if no value)
 * @param line int of the line on which the token is
 * @param start start column of the token
 * @param end end column of the token (same as start for one character tokens)
 */
void processToken(Tokenlist *list, char type[], char value[], int line, int start, int end);

/**
 * Lex a file
 *
 * @fn lex
 * @param path char array with the path to the file
 * @return a Tokenlist with all the tokens from the file
 */
Tokenlist lex(char path[]);

#endif