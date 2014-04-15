#ifndef H_TOKEN
#define H_TOKEN

typedef struct Token {
	char *type, *value;
	int line, start, end;
} Token;

#endif