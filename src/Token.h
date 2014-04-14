#ifndef H_TOKEN
#define H_TOKEN

typedef struct Token {
	char *type;
} Token;

void printToken(char type[], char value[], int line, int start, int end);

#endif