#ifndef H_TOKEN
#define H_TOKEN

typedef struct Token {
	char *tag;
	int line;
	int column;
	int end;
} Token;

void printToken(Token *token) {
	printf("---------------------------------------\n");
	printf("TOKEN\n");
	printf("---------------------------------------\n");
	printf("tag: %s\n", token->tag);
	printf("line: %d\n", token->line);
	printf("---------------------------------------\n");
}

#endif