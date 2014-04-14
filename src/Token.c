#include <stdio.h>
#include "Token.h"

void printToken(Token *token) {
	printf("---------------------------------------\n");
	printf("TOKEN\n");
	printf("---------------------------------------\n");
	printf("type: %s\n", token->type);
	printf("value: %s\n", token->value);
	printf("line: %d\n", token->line);
	printf("start: %d\n", token->start);
	printf("end: %d\n", token->end);
	printf("---------------------------------------\n");
}