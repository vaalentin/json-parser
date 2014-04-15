#ifndef H_TOKEN
#define H_TOKEN

/**
 * Struct containing all the informations relarive to a token
 * the Tokens will be passed to the parser
 *
 * @struct Token
 */
typedef struct Token {
	char *type, *value;
	int line, start, end;
} Token;

#endif