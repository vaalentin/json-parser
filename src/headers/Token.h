#ifndef H_TOKEN
#define H_TOKEN

typedef struct Token {

	char *type;
	int line, column;

} Token;

#endif