#ifndef H_TOKEN
#define H_TOKEN

typedef struct Token {
	int line, start, end;
} Token;

void printToken(char type[], char value[], int line, int start, int end);

#endif