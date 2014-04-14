#ifndef H_TOKEN
#define H_TOKEN

typedef struct Token {
	char *type;
	char *value;
	int line;
	int start;
	int end;
} Token;

void printToken(Token *token);

#endif