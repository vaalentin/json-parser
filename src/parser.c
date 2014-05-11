#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Tokenlist.h"
#include "Token.h"
#include "Parser.h"

void parse(Tokenlist *tokens) {

	Token *token;
	token = nextToken(tokens);

	while(token->type != NULL) {
		printf("%s, %s\n", token->type, token->value);
		token = nextToken(tokens);
	}

}