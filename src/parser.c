#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "Tokenlist.h"
#include "Token.h"
#include "Parser.h"


void parse(Tokenlist const *tokens) {

	for(int cursor = 0; cursor < tokens->used - 1; cursor++) {
		Token *token = &tokens->elements[cursor];
		printf("%s, %s\n", token->type, token->value);
	}

}