#include "Token.h"

#ifndef H_TOKENLIST
#define H_TOKENLIST

/**
 * Tokenlist is a Token array to which we can dynamically add new Tokens
 *
 * @struct Tokenlist
 */
typedef struct Tokenlist {
	Token *elements;
	int used, size;
} Tokenlist;

/**
 * Initialize a Tokenlist at length 0
 * by calling malloc on the elements pointer
 *
 * @fn initTokenlist
 * @param list pointer to a Tokenlist
 */
void initTokenlist(Tokenlist *list);

/**
 * Insert a new element at the end of the chunck of memory pointed by elements
 * realloc the chunck of memory if the element we're trying to insert is overflow
 *
 * @fn insertTokenlist
 * @param list pointer to a Tokenlist
 * @param token Token
 */
void insertTokenlist(Tokenlist *list, Token token);

/**
 * Dump the content of the Tokenlist with printf
 *
 * @fn dumpTokenlist
 * @param list pointer to a Tokenlist
 */
void dumpTokenlist(Tokenlist *list);

#endif